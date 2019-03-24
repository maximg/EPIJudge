
#include <thread>
#include <mutex>
#include <queue>
#include <unordered_map>
#include <memory>
#include <functional>
#include <chrono>
#include <atomic>
#include <stdexcept>
#include <condition_variable>
#include <iostream>

using namespace std;
using namespace chrono_literals;

class Timer {
    using Time = chrono::time_point<chrono::system_clock>;
    struct Job {
        string name;
        function<void()> fn;
        Time when;
        bool cancelled;

        struct Greater {
            bool operator ()(const shared_ptr<Job>& a, const shared_ptr<Job>& b) {
                return a->when > b->when;
            }
        };
    };
    using JobPtr = shared_ptr<Job>;

    unordered_map<string, JobPtr> jobs;
    priority_queue<JobPtr, vector<JobPtr>, Job::Greater> jobQueue;

    mutex mtx;
    condition_variable cv;
    atomic_bool running;
    thread runner;

    using Lock = lock_guard<mutex>;

public:
    Timer() : running(true), runner([this]{ run(); }) {}

    ~Timer() {
        cerr << "shutting down" << endl;
        running.store(false, memory_order_release);
        cv.notify_one();
        if (runner.joinable())
            runner.join();
    }

    void add(string name, Time when, function<void()> fn) {
        {
            Lock l(mtx);
            if (jobs.find(name) != jobs.end())
                throw invalid_argument("name already in use: "s + name);

            JobPtr job( new Job{name, fn, when, false});
            jobs[name] = job;
            jobQueue.push(job);
        }
        cv.notify_one();
    }

    void cancel(string name) {
        {
            Lock l(mtx);
            auto it = jobs.find(name);
            if (it != jobs.end())
                it->second->cancelled = true;
        }
        cv.notify_one();
    }

    void run() {
        while (running.load(memory_order_acquire)) {
            
            unique_lock<mutex> lk(mtx);
            if (jobQueue.empty())
                cv.wait(lk);
            else
                cv.wait_until(lk, jobQueue.top()->when);

            while (!jobQueue.empty() && jobQueue.top()->cancelled)
                jobQueue.pop();

            while (!jobQueue.empty() && 
                   chrono::system_clock::now() >= jobQueue.top()->when) {
                auto job = jobQueue.top();
                jobQueue.pop();
                jobs.erase(job->name);
                lk.unlock();
                job->fn();
                lk.lock();
            }
        }
    }
};

int main() {
    auto now = chrono::system_clock::now();

    cout << "Starting tasks..." << endl;

    Timer timer;
    timer.add("taskA", now + 100ms, [](){
        cout << "Task A done" << endl;
    });
    timer.cancel("taskA");

    timer.add("taskB", now + 100ms, [](){
        cout << "Task B done" << endl;
    });

    this_thread::sleep_for(500ms);

    cout << "done" << endl;
}

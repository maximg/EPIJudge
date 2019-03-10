
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

class RWLock {
    std::mutex m;
    std::condition_variable cv;
    int state = 0;

public:
    void lockWrite() {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this]{
            if (state > 0) return false;
            --state;
            return true;
        });
    }

    void releaseWrite() {
        {
            std::lock_guard<std::mutex> lk(m);
            ++state;
        }
        cv.notify_all();
    }

    void lockRead() {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this]{
            if (state < 0) return false;
            ++state;
            return true;
        });
        lk.unlock();
    }

    void releaseRead() {
        {
            std::lock_guard<std::mutex> lk(m);
            --state;
        }
        cv.notify_all();
    }
};

int shared_var = 0;
RWLock rwLock;
 
void write() {
    for (;;) {
        cout << "Writer: waiting for lock" << endl;

        rwLock.lockWrite();

        cout << "Writer: writing..." << endl;
        shared_var = 1000;
        this_thread::sleep_for(100ms);
        shared_var = 1;

        cout << "Writer: done" << endl;

        rwLock.releaseWrite();
    }
}

void read() {
    for (;;) {
        cout << "Reader: waiting for lock" << endl;

        rwLock.lockRead();

        cout << "Reader: reading..." << endl;
        if (shared_var == 1000) {
            cerr << "Writer lock failed!" << endl;
            exit(1);
        }
        this_thread::sleep_for(20ms);

        cout << "Reader: done" << endl;
        rwLock.releaseRead();
    }
}

int main(){
    thread writer(write);
    thread reader1(read);
    thread reader2(read);
    writer.join();
}




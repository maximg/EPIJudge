
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

// class RWLockWPref {
//     std::mutex mEntry;
//     std::condition_variable cvWork;
//     int stateEntry = 0;

//     std::mutex mWork;
//     std::condition_variable cvEntry;
//     int stateWork = 0;

// public:
//     void lockWrite() {
//         // take the entry lock
//         std::unique_lock<std::mutex> lk(mEntry);
//         cv.wait(lk, [this]{
//             if (stateEntry > 0) return false;
//             --stateEntry;
//             return true;
//         });
//     }

//     void releaseWrite() {
//         {
//             std::lock_guard<std::mutex> lk(m);
//             ++state;
//         }
//         cv.notify_all();
//     }

//     void lockRead() {
//         std::unique_lock<std::mutex> lk(m);
//         cv.wait(lk, [this]{
//             if (state < 0) return false;
//             ++state;
//             return true;
//         });
//         lk.unlock();
//     }

//     void releaseRead() {
//         {
//             std::lock_guard<std::mutex> lk(m);
//             --state;
//         }
//         cv.notify_all();
//     }
// };

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

class RWLockWPref {
    RWLock entry;
    RWLock work;
public:
    void lockWrite() {
        entry.lockWrite();
        work.lockWrite();
        entry.releaseWrite();
    }

    void releaseWrite() {
        work.releaseWrite();
    }

    void lockRead() {
        entry.lockRead();
        work.lockRead();
        entry.releaseRead();
    }

    void releaseRead() {
        work.releaseRead();
    }
};

int shared_var = 0;
RWLockWPref rwLock;
 
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





#include <mutex>
#include <atomic>
#include <thread>
#include <iostream>

using namespace std;

class Buffer {
    static constexpr size_t SIZE = 256;
    int buf[SIZE];
    std::atomic_int cons{ 0 }, prod{ 0 };
    int count = 0;
    mutex m;
    condition_variable cv;
public:
    void write(int v) {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{ return count < SIZE; });

        int pNext = (prod + 1) & 0xFF;
        buf[prod] = v;
        prod = pNext;
        ++count;
        lk.unlock();
        cv.notify_one();
    }

    void read(int *v) {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{ return count > 0; });
        *v = buf[cons];
        cons = (cons + 1) & 0xFF;
        --count;
        lk.unlock();
        cv.notify_one();
    }
};

Buffer buffer;
 
void write() {
    for (int i = 0; ; ++i) {
        buffer.write(i);
        this_thread::sleep_for(50ms);
    }
}

void read() {
    for (int i = 0; ; ++i) {
        int j = -1;
        buffer.read(&j);

        if (i != j) {
            cerr << "Sequence violation" << endl;
            exit(1);
        }
        if ((i % 10) == 0 )
            cout << i << endl;
    }

}

int main(){
    thread writer(write);
    thread reader(read);
    writer.join();
}




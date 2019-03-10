
#include <atomic>
#include <thread>
#include <iostream>

using namespace std;

class Buffer {
    static constexpr size_t SIZE = 256;
    int buf[SIZE];
    std::atomic_int cons{ 0 }, prod{ 0 };
public:
    bool write(int v) {
        int pNext = (prod + 1) & 0xFF;
        if (pNext == cons) return false;
        buf[prod] = v;
        prod = pNext;
        return true;
    }

    bool read(int *v) {
        if (prod == cons) return false;
        *v = buf[cons];
        cons = (cons + 1) & 0xFF;
        return true;
    }
};

Buffer buffer;
 
void write() {
    for (int i = 0; ; ++i) {
        while (!buffer.write(i))
            ;
    }
}

void read() {
    for (int i = 0; ; ++i) {
        int j = -1;
        while(!buffer.read(&j))
            ;
        if (i != j) {
            cerr << "Sequence violation" << endl;
            exit(1);
        }
        if ((i % 10000) == 0 )
            cout << i << endl;
    }

}

int main(){
    thread writer(write);
    thread reader(read);
    writer.join();
}




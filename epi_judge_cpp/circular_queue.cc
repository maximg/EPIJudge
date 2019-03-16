#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
#include <vector>
#include <stdexcept>
class Queue {
  std::vector<int> buf;
  size_t head = 0, tail = 0;

  size_t resize() {
    size_t tmp = (tail + 1) % buf.size();
    if (tmp != head) return tmp;

    size_t oldSize = buf.size(), newSize = oldSize*2;
    buf.resize(newSize);
    if (tail < head) {
      std::copy_backward(buf.begin() + head,
                         buf.begin() + oldSize,
                         buf.end());
      head = newSize - (oldSize - head);
    }
    return tail + 1;
  }
 public:
  Queue(size_t capacity) : buf(16) {}
  void Enqueue(int x) {
    size_t tmp = resize();
    buf[tail] = x;
    tail = tmp;
  }
  int Dequeue() {
    if (tail == head)
      throw std::logic_error("queue empty");
    size_t tmp = head;
    head = (head + 1) % buf.size();
    return buf[tmp];
  }
  int Size() const {
    return (tail > head) ? (tail - head) : ((tail + buf.size() - head) % buf.size());
  }
};
struct QueueOp {
  enum { kConstruct, kDequeue, kEnqueue, kSize } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "Queue") {
      op = kConstruct;
    } else if (op_string == "dequeue") {
      op = kDequeue;
    } else if (op_string == "enqueue") {
      op = kEnqueue;
    } else if (op_string == "size") {
      op = kSize;
    } else {
      throw std::runtime_error("Unsupported queue operation: " + op_string);
    }
  }

  void execute(Queue& q) const {
    switch (op) {
      case kConstruct:
        // Hack to bypass deleted assign operator
        q.~Queue();
        new (&q) Queue(argument);
        break;
      case kDequeue: {
        int result = q.Dequeue();
        if (result != argument) {
          throw TestFailure("Dequeue: expected " + std::to_string(argument) +
                            ", got " + std::to_string(result));
        }
      } break;
      case kEnqueue:
        q.Enqueue(argument);
        break;
      case kSize: {
        int s = q.Size();
        if (s != argument) {
          throw TestFailure("Size: expected " + std::to_string(argument) +
                            ", got " + std::to_string(s));
        }
      } break;
    }
  }
};

template <>
struct SerializationTraits<QueueOp> : UserSerTraits<QueueOp, std::string, int> {
};

void QueueTester(const std::vector<QueueOp>& ops) {
  Queue q(0);
  for (auto& op : ops) {
    op.execute(q);
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "circular_queue.cc", "circular_queue.tsv",
                         &QueueTester, DefaultComparator{}, param_names);
}

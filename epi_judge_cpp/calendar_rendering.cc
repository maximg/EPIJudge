#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Event {
  int start, finish;
};
int FindMaxSimultaneousEvents(const vector<Event>& A) {
    vector<std::pair<int, bool>> t;
    for (auto& ev: A) {
        t.push_back({ev.start, true});
        t.push_back({ev.finish+1, false});
    }
    std::sort(t.begin(), t.end(), [](const auto& a, const auto& b){
        if (a.first < b.first) return true;
        if (a.first == b.first) return (!a.second && b.second);
        return false;
    });
    int maxEv = 0;
    int count = 0;
    for (const auto& x: t) {
        count += (x.second ? 1 : -1);
        maxEv = std::max(maxEv, count);
    }
    return maxEv;
}
template <>
struct SerializationTraits<Event> : UserSerTraits<Event, int, int> {};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "calendar_rendering.cc",
                         "calendar_rendering.tsv", &FindMaxSimultaneousEvents,
                         DefaultComparator{}, param_names);
}

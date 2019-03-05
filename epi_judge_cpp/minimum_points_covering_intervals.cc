#include <vector>
#include <map>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Interval {
  int left, right;
};

int FindMinimumVisits(vector<Interval> intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
        return a.right < b.right;
    });
    vector<bool> seen(intervals.size(), false);
    std::multimap<int, size_t> lefts;
    for (size_t i = 0; i < intervals.size(); ++i)
        lefts.insert({intervals[i].left, i});

    int count = 0;
    auto it = lefts.begin();
    for (size_t i = 0; i < intervals.size(); ++i) {
        if (seen[i]) continue;
        seen[i] = true;
        ++count;
        while (it != lefts.end() && it->first <= intervals[i].right) {
            seen[it->second] = true;
            ++it;
        }
    }

    return count;
}
template <>
struct SerializationTraits<Interval> : UserSerTraits<Interval, int, int> {};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"intervals"};
  return GenericTestMain(args, "minimum_points_covering_intervals.cc",
                         "minimum_points_covering_intervals.tsv",
                         &FindMinimumVisits, DefaultComparator{}, param_names);
}

#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int helper(vector<int>::const_iterator begin, vector<int>::const_iterator end) {
    size_t dist = std::distance(begin, end);
    if (dist < 2) return 0;
    if (dist == 2) return (*begin > *(end-1)) ? 1 : 0;
    auto mid = begin + dist / 2;
    int count = helper(begin, mid) + helper(mid, end);
    vector<int> helpV(mid, end);
    std::sort(helpV.begin(), helpV.end());
    for (auto it = begin; it != mid; ++it) {
        int k = std::distance(helpV.begin(), 
                              std::lower_bound(helpV.begin(), helpV.end(), *it));
        count += k;
    }
    return count;
}

int CountInversions(vector<int> A) {
    return helper(A.begin(), A.end());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "count_inversions.cc", "count_inversions.tsv",
                         &CountInversions, DefaultComparator{}, param_names);
}

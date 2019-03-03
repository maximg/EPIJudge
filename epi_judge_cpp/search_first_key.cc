#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {
    int l = 0, h = A.size() - 1;
    int res = -1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (A[m] < k) {
            l = m + 1;
        }
        else
        if (A[m] > k)
            h = m - 1;
        else {
            res = m;
            h = m - 1;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}

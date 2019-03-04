#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
    vector<int> result;
    auto itA = A.cbegin(), itB = B.cbegin();
    while (itA != A.cend() && itB != B.cend()) {
        if (*itA < *itB) {
            ++itA;
        }
        else if (*itB < *itA) {
            ++itB;
        }
        else {
            if (result.empty() || *itA != result.back())
                result.emplace_back(*itA);
            ++itA;
            ++itB;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}

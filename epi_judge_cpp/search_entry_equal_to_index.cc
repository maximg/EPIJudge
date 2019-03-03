#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;

int SearchEntryEqualToItsIndex(const vector<int>& A) {
  if (A.empty()) return -1;
  if (A.size() == 1) return A[0] == 0 ? 0 : -1;

  if (A[0] > 0 || A.back() < A.size() - 1) return -1;

  int l = 0, h = A.size() - 1;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (A[m] > m)
      h = m - 1;
    else
    if (A[m] < m)
      l = m + 1;
    else
      return m;
  }
  return 0;
}
void SearchEntryEqualToItsIndexWrapper(TimedExecutor& executor,
                                       const vector<int>& A) {
  int result = executor.Run([&] { return SearchEntryEqualToItsIndex(A); });

  if (result != -1) {
    if (A[result] != result) {
      throw TestFailure("Entry does not equal to its index");
    }
  } else {
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] == i) {
        throw TestFailure("There are entries which equal to its index");
      }
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(
      args, "search_entry_equal_to_index.cc", "search_entry_equal_to_index.tsv",
      &SearchEntryEqualToItsIndexWrapper, DefaultComparator{}, param_names);
}

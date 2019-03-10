#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

bool collatzHelper(vector<bool>& collatz, long long n) {
  if (collatz.size() <= (n+1) / 2)
    collatz.resize((n+1)/2, false);

  if (collatz[(n-1)/2])
    return true;

  if (n & 1) {
    collatz[(n-1)/2] = collatzHelper(collatz, 3 * n + 1);
    return collatz[(n-1)/2];
  }
  else
    return collatzHelper(collatz, n / 2);
}

bool TestCollatzConjecture(int n) {
    vector<bool> collatz(n, false);
    collatz[0] = true;
    for (int i = 2; i <= n; ++i)
        if (!collatzHelper(collatz, i))
            return false;
    return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "collatz_checker.cc", "collatz_checker.tsv",
                         &TestCollatzConjecture, DefaultComparator{},
                         param_names);
}

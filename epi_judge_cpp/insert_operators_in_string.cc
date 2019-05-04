#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

bool helper(const vector<int>& digits, int pos, int target, int mult, int prefix) {
    if (target < 0)
        return false;

    int term = (prefix * 10 + digits[pos]) * mult;
    if (pos == digits.size() - 1)
        return target == term;

    // try sum
    if (helper(digits, pos + 1, target - term, 1, 0))
        return true;

    // try mult
    if (helper(digits, pos + 1, target, term, 0))
        return true;

    // try concat
    return helper(digits, pos + 1, target, mult, prefix * 10 + digits[pos]);
}

bool ExpressionSynthesis(const vector<int>& digits, int target) {
  return helper(digits, 0, target, 1, 0);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"digits", "target"};
  return GenericTestMain(args, "insert_operators_in_string.cc",
                         "insert_operators_in_string.tsv", &ExpressionSynthesis,
                         DefaultComparator{}, param_names);
}

#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Jug {
  int low, high;
};
bool CheckFeasible(const vector<Jug>& jugs, int L, int H) {
    std::unordered_map<int, int> M;
    for (auto& j: jugs) {
        if (M.find(j.low) == M.end())
            M[j.low] = j.high;
        else
            M[j.low] = std::min(M[j.low], j.high);
    }

    // dp[i] indicates the max possible error if the min error is i
    // we allow for min error to be greater than L so we need H elements
    vector<int> dp(H);
    for (size_t i = 0; i < H; ++i) {
        if (M.find(i) != M.end())
            dp[i] = M[i];

        for (size_t j = 0; j < i ; ++j) {
            if (dp[j] != 0 && M.find(i-j) != M.end()) {
                if (dp[i] > 0)
                    dp[i] = std::min(dp[i], dp[j] + M[i-j]);
                else
                    dp[i] = dp[j] + M[i-j];            }
        }

        if (i >=L && dp[i] > 0 && dp[i] <= H)
            return true;
    }

  return false;
}
template <>
struct SerializationTraits<Jug> : UserSerTraits<Jug, int, int> {};

bool operator==(const Jug& lhs, const Jug& rhs) {
  return lhs.low == rhs.low && lhs.high == rhs.high;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"jugs", "L", "H"};
  return GenericTestMain(args, "defective_jugs.cc", "defective_jugs.tsv",
                         &CheckFeasible, DefaultComparator{}, param_names);
}

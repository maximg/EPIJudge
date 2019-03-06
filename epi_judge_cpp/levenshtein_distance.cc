#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;


int LevenshteinDistance(const string& A, const string& B) {
    if (A.empty() || B.empty())
        return std::max(A.size(), B.size());

    vector<int> cost(A.size()+1);
    iota(cost.begin(), cost.end(), 0);
 
    for (int i = 0; i < B.size(); ++i) {
        vector<int> newcost(A.size()+1);
        newcost[0] = cost[0] + 1;

        for (int j = 0; j < A.size(); ++j) {
            newcost[j+1] = std::min( std::min(cost[j+1]+1, newcost[j]+1),
                cost[j] + (A[j] == B[i] ? 0 : 1));
        }
        std::swap(cost, newcost);
    }

    return cost.back();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "levenshtein_distance.cc",
                         "levenshtein_distance.tsv", &LevenshteinDistance,
                         DefaultComparator{}, param_names);
}

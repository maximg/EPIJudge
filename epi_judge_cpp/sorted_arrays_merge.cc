#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;
using std::pair;

template<>
struct std::greater<pair<int, int>>
{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;
    }
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {

    if (sorted_arrays.empty()) return {};
    
    std::priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        std::greater<pair<int, int>>> minHeap;
    vector<vector<int>::const_iterator> heads;

    for (int i = 0; i < sorted_arrays.size(); ++i) {
        heads.push_back(sorted_arrays[i].begin());
        if (heads[i] != sorted_arrays[i].end())
            minHeap.push({i, *(heads[i]++)});
    }

    vector<int> out;
    while (!minHeap.empty()) {
        out.emplace_back(minHeap.top().second);
        int i = minHeap.top().first;
        minHeap.pop();
        if (heads[i] != sorted_arrays[i].end())
            minHeap.push({i, *(heads[i]++)});            
    }

    return out;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}

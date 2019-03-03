#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;
vector<int> SortApproximatelySortedData(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end, int k) {

    std::priority_queue<int, vector<int>, std::greater<int>> minHeap;

    vector<int> out;

    for (int i = 0; i < k; ++i)
      if (sequence_begin != sequence_end)
        minHeap.push(*sequence_begin++);

    while (sequence_begin != sequence_end) {
      minHeap.push(*sequence_begin++);
      out.emplace_back(minHeap.top());
      minHeap.pop();
    }

    while (!minHeap.empty()) {
      out.emplace_back(minHeap.top());
      minHeap.pop();      
    }

    return out;
}
vector<int> SortApproximatelySortedDataWrapper(const vector<int>& sequence,
                                               int k) {
  return SortApproximatelySortedData(cbegin(sequence), cend(sequence), k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence", "k"};
  return GenericTestMain(
      args, "sort_almost_sorted_array.cc", "sort_almost_sorted_array.tsv",
      &SortApproximatelySortedDataWrapper, DefaultComparator{}, param_names);
}

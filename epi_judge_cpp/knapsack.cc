#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Item {
  int weight, value;
};

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity) {
  vector<int> knapsack(capacity + 1, 0);
  for (auto item: items) {
    for (int i = capacity; i >= item.weight; --i) {
        knapsack[i] = std::max(knapsack[i], knapsack[i - item.weight] + item.value);
    }
  }
  return knapsack[capacity];
}
template <>
struct SerializationTraits<Item> : UserSerTraits<Item, int, int> {};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"items", "capacity"};
  return GenericTestMain(args, "knapsack.cc", "knapsack.tsv",
                         &OptimumSubjectToCapacity, DefaultComparator{},
                         param_names);
}

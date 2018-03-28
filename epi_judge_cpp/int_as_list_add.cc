#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> AddTwoNumbers(shared_ptr<ListNode<int>> L1,
                                        shared_ptr<ListNode<int>> L2) {
  // Implement this placeholder.
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "int_as_list_add.tsv", &AddTwoNumbers,
                         DefaultComparator{}, param_names);
}

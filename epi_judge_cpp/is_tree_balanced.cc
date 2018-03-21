
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.tsv", &IsBalanced,
                         DefaultComparator{}, param_names);
}

#include <vector>

#include "binary_tree_with_parent_prototype.h"

using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  GenericTestMain(args, "tree_with_parent_inorder.tsv", &InorderTraversal,
                  DefaultComparator{}, param_names);
  return 0;
}

#include <memory>
#include <vector>

#include "binary_tree_node.h"

using std::unique_ptr;
using std::vector;

// We use stack and previous node pointer to simulate postorder traversal.
vector<int> PostorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  GenericTestMain(args, "tree_postorder.tsv", &PostorderTraversal,
                  DefaultComparator{}, param_names);
  return 0;
}

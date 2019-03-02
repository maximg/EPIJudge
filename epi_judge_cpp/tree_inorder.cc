#include <memory>
#include <vector>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  if (!tree) return {};

  using NodePtr = const BinaryTreeNode<int>*;
  vector<int> result;
  vector<std::pair<NodePtr, int>> stack;

  stack.push_back({tree.get(), 0});
  while (!stack.empty()) {
    auto& current = stack.back();
    if (current.second == 0) {
        current.second = 1;
        // if we can, go left
        if (current.first->left)
            stack.push_back({current.first->left.get(), 0});
    }
    else if (current.second == 1) {
        result.push_back(current.first->data);
        current.second = 2;
        if (current.first->right)
            stack.push_back({current.first->right.get(), 0});
    }
    else // 2
        stack.pop_back();
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_inorder.cc", "tree_inorder.tsv",
                         &InorderTraversal, DefaultComparator{}, param_names);
}

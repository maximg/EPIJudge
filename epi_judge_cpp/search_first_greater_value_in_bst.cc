#include <memory>
#include "bst_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

BstNode<int>* minElement(const unique_ptr<BstNode<int>>& tree) {
    if (!tree) return nullptr;
    return tree->left ? minElement(tree->left) : tree.get();
}

BstNode<int>* helper(const unique_ptr<BstNode<int>>& tree,
                     int k,
                     BstNode<int>* candidate) {
    // if k is equal to data, return ptr to min of right tree
    // otherwise return succ(k) of left or right tree
    if (!tree) return candidate;
    if (tree->data < k) {
        return helper(tree->right, k, candidate);
    }
    if (tree->data == k) {
      if (tree->right)
        return minElement(tree->right);
      else
        return candidate;
    }
    if (tree->data > k) {
        return helper(tree->left, k, tree.get());
    }
    return nullptr;
}

BstNode<int>* FindFirstGreaterThanK(const unique_ptr<BstNode<int>>& tree,
                                    int k) {
    return helper(tree, k, nullptr);
}

int FindFirstGreaterThanKWrapper(const unique_ptr<BstNode<int>>& tree, int k) {
  auto result = FindFirstGreaterThanK(tree, k);
  return result ? result->data : -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "k"};
  return GenericTestMain(args, "search_first_greater_value_in_bst.cc",
                         "search_first_greater_value_in_bst.tsv",
                         &FindFirstGreaterThanKWrapper, DefaultComparator{},
                         param_names);
}

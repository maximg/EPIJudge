#include <memory>
#include "bst_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;


BstNode<int>* FindFirstGreaterThanK(const unique_ptr<BstNode<int>>& tree,
                                    int k) {
  if (!tree) return nullptr;
  auto current = tree.get();
  BstNode<int>* candidate = nullptr;
  while (true) {
    if (current->data > k) { //left subtree
      if (current->left) {
        candidate = current;
        current = current->left.get();
      }
      else
        return current;
    }
    else if (current->data == k) {  // right subtree
      if (current->right)
        candidate = current = current->right.get();
      else
        return candidate;
    }
    else {  // current->data < k, right subtree
      if (current->right)
        current = current->right.get();
      else
        return candidate;
    }
  }
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

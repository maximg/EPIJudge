#include <memory>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

// The tree must be a BST within the range lower / upper
bool helper(const unique_ptr<BinaryTreeNode<int>>& node, int lower, int upper) {
    if (!node)
        return true;

    if (node->data < lower || node->data > upper)
        return false;

    return helper(node->left, lower, node->data) && 
           helper(node->right, node->data, upper);
}


bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
    // BST property is: all nodes to the left are less than root
    // all nodes to the right are greater than root

    // We could check this recursively, adding an upper bound and lower bound

    return helper(tree, INT_MIN, INT_MAX);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}

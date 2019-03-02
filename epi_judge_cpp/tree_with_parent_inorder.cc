#include <vector>
#include "binary_tree_with_parent_prototype.h"
#include "test_framework/generic_test.h"
using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
    using NodePtr = BinaryTreeNode<int>*;
    if (!tree) return {};

    // we keep a pointer to the previous node to check where we are coming to a node
    vector<int> out;

    NodePtr prev = nullptr;
    NodePtr cur = tree.get();

    while (true) {
        enum { LEFT, RIGHT, UP } dir;

        if (prev == cur->parent) {
            if (cur->left)
                dir = LEFT;
            else 
                dir = RIGHT;
        }
        else
        if (prev == cur->left.get())
            dir = RIGHT;
        else {
            assert( prev == cur->right.get());
            dir = UP;
        }
        prev = cur;

        switch (dir) {
            case LEFT: cur = cur->left.get(); break;
            case RIGHT:
                out.push_back(cur->data);
                if (cur->right) {
                    cur = cur->right.get();
                    break;
                }
                // Fallthrough
            case UP: {
                if (cur->parent)
                    cur = cur->parent;
                else
                    return out;
            }
        }
    }
    return out;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_with_parent_inorder.cc",
                         "tree_with_parent_inorder.tsv", &InorderTraversal,
                         DefaultComparator{}, param_names);
}

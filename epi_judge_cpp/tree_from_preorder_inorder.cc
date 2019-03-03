#include <vector>
#include <unordered_map>
#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
using std::vector;


unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(
    const vector<int>& preorder, const vector<int>& inorder) {

    if (preorder.empty()) return {};

    std::unordered_map<int, int> order;
    for (int i = 0; i < inorder.size(); ++i)
        order[inorder[i]] = i;

    vector<BinaryTreeNode<int>*> path;
    auto root = std::make_unique<BinaryTreeNode<int>>(preorder[0]);

    BinaryTreeNode<int>* cur = root.get();
    path.push_back(cur);

    for (int i = 1; i < preorder.size(); ++i) {
        auto next = std::make_unique<BinaryTreeNode<int>>(preorder[i]);
        if (order[preorder[i]] < order[cur->data]) {
            cur->left = std::move(next);
            cur = cur->left.get();
            path.push_back(cur);
        }
        else {
            // follow the path up to find the closest node to next
            int dist = INT_MAX;
            int j = path.size();
            for ( ; j > 0; --j) {
                int cur_dist = order[preorder[i]] - order[path[j-1]->data];
                if (cur_dist < 0) break;
                if (cur_dist < dist) {
                  dist = cur_dist;
                  cur = path[j-1];
                }
            }
            cur->right = std::move(next);
            path.resize(j);
            cur = cur->right.get();
            path.push_back(cur);
        }
    }

    return root;
}


int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder", "inorder"};
  return GenericTestMain(
      args, "tree_from_preorder_inorder.cc", "tree_from_preorder_inorder.tsv",
      &BinaryTreeFromPreorderInorder, DefaultComparator{}, param_names);
}

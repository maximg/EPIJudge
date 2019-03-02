#include <memory>
#include <vector>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (!tree)
        return {};

    vector<vector<int>> out;

    std::queue<BinaryTreeNode<int>*> bfs;
    bfs.push(nullptr);
    bfs.push(tree.get());

    while (!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();
        if (cur) {
            out.back().push_back(cur->data);
            if (cur->left)
                bfs.push(cur->left.get());
            if (cur->right)
                bfs.push(cur->right.get());  
        }
        else if(!bfs.empty()) {
            out.push_back({});
            bfs.push(nullptr);
        }
    }

    return out;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_level_order.cc", "tree_level_order.tsv",
                         &BinaryTreeDepthOrder, DefaultComparator{},
                         param_names);
}

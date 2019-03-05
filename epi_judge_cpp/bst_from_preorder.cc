#include <memory>
#include <unordered_map>
#include <vector>
#include "bst_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
    if (preorder_sequence.empty()) return nullptr;
    
    vector<int> inorder(preorder_sequence);
    std::sort(inorder.begin(), inorder.end());

    std::unordered_map<int, int> order;
    for (int i = 0; i < inorder.size(); ++i)
        order[inorder[i]] = i;

    vector<BstNode<int>*> path;
    auto root = std::make_unique<BstNode<int>>(preorder_sequence[0]);

    BstNode<int>* cur = root.get();
    path.push_back(cur);

    for (int i = 1; i < preorder_sequence.size(); ++i) {
        auto next = std::make_unique<BstNode<int>>(preorder_sequence[i]);
        if (order[preorder_sequence[i]] < order[cur->data]) {
            cur->left = std::move(next);
            cur = cur->left.get();
            path.push_back(cur);
        }
        else {
            // follow the path up to find the closest node to next
            int dist = INT_MAX;
            int j = path.size();
            for ( ; j > 0; --j) {
                int cur_dist = order[preorder_sequence[i]] - order[path[j-1]->data];
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
  std::vector<std::string> param_names{"preorder_sequence"};
  return GenericTestMain(args, "bst_from_preorder.cc", "bst_from_preorder.tsv",
                         &RebuildBSTFromPreorder, DefaultComparator{},
                         param_names);
}

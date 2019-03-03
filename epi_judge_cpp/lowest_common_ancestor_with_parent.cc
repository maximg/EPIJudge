#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

int depth(BinaryTreeNode<int>* node) {
  int count = 0;
  while (node->parent) {
    node = node->parent;
    ++count;
  }
  return count;
}

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  if (!node0 || !node1)
    return nullptr;

  auto p0 = node0.get(), p1 = node1.get();
  int depth0 = depth(p0), depth1 = depth(p1);
  if (depth0 < depth1)
    std::swap(p0, p1);

  for (int i = 0; i < abs(depth0 - depth1); ++i)
    p0 = p0->parent;

  while (p0 && p1 && p0 != p1) {
    p0 = p0->parent;
    p1 = p1->parent;
  }
  return p0;
}

int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return LCA(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}

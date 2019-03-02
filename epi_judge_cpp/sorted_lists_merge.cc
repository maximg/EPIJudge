#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
    auto head = make_shared<ListNode<int>>();
    auto tail = head;

    while (L1 && L2) {
        auto& next = (L1->data < L2->data) ? L1 : L2;
        tail->next = next;
        tail = tail->next;
        next = next->next;
    }
    tail->next = L1 ? L1 : L2;

    return head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}

#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>>& L) {
  if (!L || !L->next || !L->next->next)
    return L;

  auto LOdd = L->next;

  auto curEven = L;
  auto curOdd = L->next;
  while (curOdd && curOdd->next && curOdd->next->next) {
    curEven = curEven->next = curOdd->next;
    curOdd = curOdd->next = curOdd->next->next;
  }

  if (curOdd->next) {
    curEven = curEven->next = curOdd->next;
    curOdd->next = nullptr;
  }

  curEven->next = LOdd;

  return L;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "even_odd_list_merge.cc",
                         "even_odd_list_merge.tsv", &EvenOddMerge,
                         DefaultComparator{}, param_names);
}

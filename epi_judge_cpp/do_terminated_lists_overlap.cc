#include <memory>
#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::shared_ptr;

shared_ptr<ListNode<int>> OverlappingNoCycleLists(
    shared_ptr<ListNode<int>> l0, shared_ptr<ListNode<int>> l1) {

  if (!l0 || !l1) return nullptr;
  
  int len0 = 0, len1 = 0;
  shared_ptr<ListNode<int>> l0last, l1last;
  for (auto l0t = l0; (l0t = l0t->next); ++len0)
    l0last = l0t;
  for (auto l1t = l1; (l1t = l1t->next); ++len1)
    l1last = l1t;

  if (l0last != l1last) return nullptr;

  if (len0 < len1)
    std::swap(l0, l1);

  for ( int i = 0; i < abs(len0 - len1); ++i)
    l0 = l0->next;

  while (l0 && l1) {
    if (l0 == l1)
      return l0;
    l0 = l0->next;
    l1 = l1->next;
  }

  return nullptr;
}

void OverlappingNoCycleListsWrapper(TimedExecutor& executor,
                                    shared_ptr<ListNode<int>> l0,
                                    shared_ptr<ListNode<int>> l1,
                                    shared_ptr<ListNode<int>> common) {
  if (common) {
    if (l0) {
      auto i = l0;
      while (i->next) {
        i = i->next;
      }
      i->next = common;
    } else {
      l0 = common;
    }

    if (l1) {
      auto i = l1;
      while (i->next) {
        i = i->next;
      }
      i->next = common;
    } else {
      l1 = common;
    }
  }

  auto result = executor.Run([&] { return OverlappingNoCycleLists(l0, l1); });

  if (result != common) {
    throw TestFailure("Invalid result");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "l0", "l1", "common"};
  return GenericTestMain(
      args, "do_terminated_lists_overlap.cc", "do_terminated_lists_overlap.tsv",
      &OverlappingNoCycleListsWrapper, DefaultComparator{}, param_names);
}

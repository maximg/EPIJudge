package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ZipList {
  @EpiTest(testfile = "zip_list.tsv")

  public static ListNode<Integer> zippingLinkedList(ListNode<Integer> L) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTest.runFromAnnotations(
        args, new Object() {}.getClass().getEnclosingClass());
  }
}

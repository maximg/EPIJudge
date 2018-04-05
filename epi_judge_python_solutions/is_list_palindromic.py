from sys import exit

from list_node import ListNode
from reverse_linked_list_iterative import reverse_linked_list
from test_framework import generic_test, test_utils


def is_linked_list_a_palindrome(L):
    # Finds the second half of L.
    slow = fast = L
    while fast and fast.next:
        fast, slow = fast.next.next, slow.next

    # Compares the first half and the reversed second half lists.
    first_half_iter, second_half_iter = L, reverse_linked_list(slow)
    while second_half_iter and first_half_iter:
        if second_half_iter.data != first_half_iter.data:
            return False
        second_half_iter, first_half_iter = (second_half_iter.next,
                                             first_half_iter.next)
    return True


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('is_list_palindromic.tsv',
                                       is_linked_list_a_palindrome))

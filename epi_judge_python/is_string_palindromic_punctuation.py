def is_palindrome(s):
    # Implement this placeholder.
    return True


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("is_string_palindromic_punctuation.tsv",
                                       is_palindrome))

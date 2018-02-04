from test_framework.test_utils import enable_timer_hook


# Assume s is a string encoded as bytearray.
def reverse_words(s):
    # Implement this placeholder.
    return


@enable_timer_hook
def reverse_words_wrapper(timer, s):
    s_copy = bytearray()
    s_copy.extend(map(ord, s))

    timer.start()
    reverse_words(s_copy)
    timer.stop()

    return s_copy.decode("utf-8")


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('reverse_words.tsv', reverse_words_wrapper)

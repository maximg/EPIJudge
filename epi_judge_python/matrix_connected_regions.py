def flip_color(x, y, image):
    # Implement this placeholder.
    return


def flip_color_wrapper(x, y, image):
    flip_color(x, y, image)
    return image


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('painting.tsv', flip_color_wrapper)

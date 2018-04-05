def n_queens(n):
    def solve_n_queens(row):
        if row == n:
            # All queens are legally placed.
            result.append(list(col_placement))
            return
        for col in range(n):
            # Test if a newly placed queen will conflict any earlier queens
            # placed before.
            if all(
                    abs(c - col) not in (0, row - i)
                    for i, c in enumerate(col_placement[:row])):
                col_placement[row] = col
                solve_n_queens(row + 1)

    result, col_placement = [], [0] * n
    solve_n_queens(0)
    return result


def comp(a, b):
    return sorted(a) == sorted(b)


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(generic_test.generic_test_main('n_queens.tsv', n_queens, comp))

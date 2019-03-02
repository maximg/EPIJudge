#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

// Check if a partially filled matrix has any conflicts.
bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {
  auto& A = partial_assignment;

  for (int i = 0; i < 9; ++i) {
    int seen = 0;
    for (int j = 0; j < 9; ++j) {
      if (A[i][j]) {
        if (seen & (1 << A[i][j])) return false;
        seen |= 1 << A[i][j];
      }
    }
  }
  for (int j = 0; j < 9; ++j) {
    int seen = 0;
    for (int i = 0; i < 9; ++i) {
      if (A[i][j]) {
        if (seen & (1 << A[i][j])) return false;
        seen |= 1 << A[i][j];
      }
    }
  }

  for (int k = 0; k < 9; k += 3)
    for (int m = 0; m < 9; m += 3) {
      int seen = 0;
      for (int i = k; i < k+3; ++i) {
        for (int j = m; j < m+3; ++j) {
          if (A[i][j]) {
            if (seen & (1 << A[i][j])) return false;
            seen |= 1 << A[i][j];
          }
        }
      }
    }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"partial_assignment"};
  return GenericTestMain(args, "is_valid_sudoku.cc", "is_valid_sudoku.tsv",
                         &IsValidSudoku, DefaultComparator{}, param_names);
}

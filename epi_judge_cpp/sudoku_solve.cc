#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::begin;
using std::end;
using std::vector;


class Sudoku {
  using Board = vector<vector<int>>;
  Board& board;
  vector<vector<int>> missingDigs;
  vector<vector<int>> spaces;

  int blockStart[9] = {0,0,0,3,3,3,6,6,6};
  int blockEnd[9] = {3,3,3,6,6,6,9,9,9};

public:
  explicit Sudoku(vector<vector<int>>& board) : board(board) {
    for (int i = 0; i < board.size(); ++i) {
      vector<bool> digs(10);
      spaces.push_back({});
      for (int j = 0; j < board.size(); ++j) {
        if (board[i][j] > 0)
          digs[board[i][j]] = true;
        else
          spaces.back().push_back(j);
      }
      missingDigs.push_back({});
      for (int j = 1; j <= 9; ++j)
        if (!digs[j])
          missingDigs.back().push_back(j);
    }
  }

  bool solve() {
    return processRow(0);
  }

private:
  bool checkCol(int col, int dig) {
    for (int i = 0; i < board.size(); ++i)
      if (board[i][col] == dig)
        return false;
    return true;
  }

  bool checkBlock(int row, int col, int dig) {

    for (int i = blockStart[row]; i < blockEnd[row]; ++i )
      for (int j = blockStart[col]; j < blockEnd[col]; ++j )
        if (board[i][j] == dig)
          return false;
    return true;
  }

  bool placeDigs(int row, const vector<int>& missing) {
    for (int i = 0; i < missing.size(); ++i) {
      int col = spaces[row][i];
      if (!checkCol(col, missing[i]) || !checkBlock(row, col, missing[i]) )
        return false;
      else
        board[row][col] = missing[i];
    }
    return true;
  };

  bool processRow(int row) {
    if (row == board.size())
        return true;

    // build vectors of missing digits per row
    // for each row, go through permutations of possible digits
    // for each permutation try adding digits to the puzzle
    // abort as soon as there is a violation
    // if all digits are placed, move to the next row
    // if next row fails, try the next permutation

    // create copies
    auto origRow = board[row];
    auto missing = missingDigs[row];
    do {
      if (placeDigs(row, missing) && processRow(row + 1))
        return true;
      board[row] = origRow;
    }
    while (next_permutation(missing.begin(), missing.end()));

    return false;
  }
};

bool SolveSudoku(vector<vector<int>>* partial_assignment) {
  return Sudoku(*partial_assignment).solve();
}

vector<int> GatherColumn(const vector<vector<int>>& data, size_t i) {
  vector<int> result;
  for (auto& row : data) {
    result.push_back(row[i]);
  }
  return result;
}

vector<int> GatherSquareBlock(const vector<vector<int>>& data,
                              size_t block_size, size_t n) {
  vector<int> result;
  size_t block_x = n % block_size;
  size_t block_y = n / block_size;
  for (size_t i = block_x * block_size; i < (block_x + 1) * block_size; i++) {
    for (size_t j = block_y * block_size; j < (block_y + 1) * block_size; j++) {
      result.push_back(data[i][j]);
    }
  }

  return result;
}

void AssertUniqueSeq(const vector<int>& seq) {
  vector<bool> seen(seq.size(), false);
  for (auto& x : seq) {
    if (x == 0) {
      throw TestFailure("Cell left uninitialized");
    }
    if (x < 0 || x > seq.size()) {
      throw TestFailure("Cell value out of range");
    }
    if (seen[x - 1]) {
      throw TestFailure("Duplicate value in section");
    }
    seen[x - 1] = true;
  }
}

void SolveSudokuWrapper(TimedExecutor& executor,
                        const vector<vector<int>>& partial_assignment) {
  vector<vector<int>> solved = partial_assignment;

  executor.Run([&] { SolveSudoku(&solved); });

  if (!std::equal(begin(partial_assignment), end(partial_assignment),
                  begin(solved), end(solved), [](auto br, auto cr) {
                    return std::equal(begin(br), end(br), begin(cr), end(cr),
                                      [](int bcell, int ccell) {
                                        return bcell == 0 || bcell == ccell;
                                      });
                  }))
    throw TestFailure("Initial cell assignment has been changed");

  auto block_size = static_cast<size_t>(sqrt(solved.size()));

  for (size_t i = 0; i < solved.size(); i++) {
    AssertUniqueSeq(solved[i]);
    AssertUniqueSeq(GatherColumn(solved, i));
    AssertUniqueSeq(GatherSquareBlock(solved, block_size, i));
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "partial_assignment"};
  return GenericTestMain(args, "sudoku_solve.cc", "sudoku_solve.tsv",
                         &SolveSudokuWrapper, DefaultComparator{}, param_names);
}

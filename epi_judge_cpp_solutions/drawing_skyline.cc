#include <algorithm>
#include <vector>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::max;
using std::min;
using std::numeric_limits;
using std::vector;

namespace drawing_skyline {
struct Rectangle;
typedef vector<Rectangle> Skyline;

struct Rectangle {
  int left, right, height;
};
typedef vector<Rectangle> Skyline;

Skyline ComputeSkyline(const vector<Rectangle>& buildings) {
  int min_left = numeric_limits<int>::max(),
      max_right = numeric_limits<int>::min();
  for (const Rectangle& building : buildings) {
    min_left = min(min_left, building.left);
    max_right = max(max_right, building.right);
  }

  vector<int> heights(max_right - min_left + 1, 0);
  for (const Rectangle& building : buildings) {
    for (int i = building.left; i <= building.right; ++i) {
      heights[i - min_left] = max(heights[i - min_left], building.height);
    }
  }

  Skyline result;
  int left = 0;
  for (int i = 1; i < size(heights); ++i) {
    if (heights[i] != heights[i - 1]) {
      result.emplace_back(
          Rectangle{left + min_left, i - 1 + min_left, heights[i - 1]});
      left = i;
    }
  }
  result.emplace_back(Rectangle{left + min_left, max_right, heights.back()});
  return result;
}

bool operator==(const Rectangle& a, const Rectangle& b) {
  return a.left == b.left && a.right == b.right && a.height == b.height;
}
}  // namespace drawing_skyline

using drawing_skyline::ComputeSkyline;

template <>
struct SerializationTraits<drawing_skyline::Rectangle>
    : UserSerTraits<drawing_skyline::Rectangle, int, int, int> {};

std::ostream& operator<<(std::ostream& out,
                         const drawing_skyline::Rectangle& r) {
  return PrintTo(out, std::make_tuple(r.left, r.right, r.height));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"buildings"};
  return GenericTestMain(args, "drawing_skyline.cc", "drawing_skyline.tsv",
                         &ComputeSkyline, DefaultComparator{}, param_names);
}

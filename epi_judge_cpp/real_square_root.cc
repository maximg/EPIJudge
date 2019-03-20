#include "test_framework/generic_test.h"
#include <stdexcept>
#include <limits>


int compare(double a, double b) {
    double diff = (a - b) / b;
    return (diff < -std::numeric_limits<double>::epsilon()
            ? -1
            : diff > std::numeric_limits<double>::epsilon());
}

double SquareRoot(double x) {
    if (x < 0.0) throw std::invalid_argument("negative x");
    double l, h, res;
    if (x > 1.0) {
        l = 1.0; h = x;
    }
    else {
        l = x; h = 1.0;
    }
    while (compare(l, h) < 0) {
        res = l + 0.5 * (h-l);
        double res2 = res * res;
        if (compare(res2, x) == 0)
            return res;
        else if (compare(res2, x) > 0)
            h = res;
        else
            l = res;
    }
    return l;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "real_square_root.cc", "real_square_root.tsv",
                         &SquareRoot, DefaultComparator{}, param_names);
}

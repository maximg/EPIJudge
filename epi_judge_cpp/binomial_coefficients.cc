#include "test_framework/generic_test.h"

#include <cassert>

int gcd(int a, int b) {
    while (b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int ComputeBinomialCoefficient(int n, int k) {

    int binom = 1;
    for (int i = k + 1; i <= n; ++i) {
        int div = i - k;
        int gcd_i = gcd(i, div);
        div /= gcd_i;
        binom = (binom / div) * (i / gcd_i);
    }
    return binom;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  return GenericTestMain(
      args, "binomial_coefficients.cc", "binomial_coefficients.tsv",
      &ComputeBinomialCoefficient, DefaultComparator{}, param_names);
}

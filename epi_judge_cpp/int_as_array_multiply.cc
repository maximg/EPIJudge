#include <vector>
#include "test_framework/generic_test.h"
#include <cmath>
using std::vector;
vector<int> Multiply(vector<int> num1, vector<int> num2) {

    int sign = num1[0] * num2[0] > 0 ? 1 : -1;
    num1[0] = abs(num1[0]);
    num2[0] = abs(num2[0]);

    vector<int> res(num1.size() + num2.size() - 1, 0);
    for (int j = 0; j < num2.size(); ++j)
        if (num2[j])
            for (int i = 0; i < num1.size(); ++i)
                res[res.size()-(i+j)-1] += num1[i] * num2[j];

    long long carry = 0;
    for (int i = 0; i < res.size(); ++i) {
        res[i] += carry;
        if (res[i] > 9) {
            int d = res[i] % 10;
            carry = std::floor(res[i] / 10.0);
            res[i] = d;
        }
        else
            carry = 0;
    }
    if (carry)
        res.push_back(carry % 10);

    while (res.size() > 1 && res.back() == 0)
        res.resize(res.size() - 1);

    res.back() *= sign;

    return vector<int>(res.rbegin(), res.rend());
}
int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}

#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {

    vector<int> primes;
    if (n < 2) return primes;
    primes.emplace_back(2);

    size_t size = n+1;

    vector<bool> is_prime(size, true);

    for (int i = 3; i < size; i+=2) {
        if (!is_prime[i])
            continue;
        primes.emplace_back(i);
        for (int j = i * i; j < size; j += i)
            is_prime[j] = false;
    }

    return primes;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}

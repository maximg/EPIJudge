#include <string>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::string;

bool CanFormPalindrome(const string& s) {
  std::unordered_map<char, int> freqs;
  for (char c: s) {
  	freqs[c]++;
  }
  int odds = 0, evens = 0;
  for (auto p: freqs) {
  	if (p.second & 1)
  		++odds;
  	else
  		++evens;
  }
  return odds < 2;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_permutable_to_palindrome.cc",
                         "is_string_permutable_to_palindrome.tsv",
                         &CanFormPalindrome, DefaultComparator{}, param_names);
}

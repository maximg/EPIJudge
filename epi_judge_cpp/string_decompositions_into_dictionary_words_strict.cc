#include <string>
#include <vector>
#include <unordered_set>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;

vector<int> FindAllSubstrings(const string& s, const vector<string>& words) {
  std::unordered_set<string> dict;
  for (auto& w: words)
    dict.insert(w);

  // dp[i] = length of word ending at s[i]
  vector<size_t> dp(s.length(), 0);
  for (size_t i = 0; i < dp.size(); ++i) {
    if (dict.find(s.substr(0, i+1)) != dict.end())
      dp[i] = i+1;

      for (size_t j = 0; dp[i] == 0 && j < i; ++j) {
        if (dp[j] > 0 && dict.find(s.substr(j+1, i-j)) != dict.end())
            dp[i] = i-j;
      }
  }
  if (dp.back() == 0) return {};
  
  vector<int> res;
  for (size_t i = dp.size(); i > 0; ) {
    res.push_back(i-1);
    i -= dp[i-1];
  }
  return vector<int>(res.rbegin(), res.rend());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s", "words"};
  return GenericTestMain(args, "string_decompositions_into_dictionary_words.cc",
                         "string_decompositions_into_dictionary_words.tsv",
                         &FindAllSubstrings, DefaultComparator{}, param_names);
}

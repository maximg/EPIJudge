#include <string>
#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;
using namespace std;

vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {
    vector<vector<string>> anagrams;
    unordered_map<string, size_t> index;

    for (const auto& word : dictionary) {
        string key = word;
        sort(key.begin(), key.end());
        auto it = index.find(key);
        if (it != index.end()) {
            anagrams[it->second].emplace_back(word);
        }
        else {
            anagrams.emplace_back(vector<string>{word});
            index[key] = anagrams.size() - 1;
        }
    }
    anagrams.erase(partition(anagrams.begin(), anagrams.end(),
                            [](const auto& vec) { return vec.size() > 1; }),
                   anagrams.end());
    return anagrams;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"dictionary"};
  return GenericTestMain(
      args, "anagrams.cc", "anagrams.tsv", &FindAnagrams,
      &UnorderedComparator<std::vector<std::vector<std::string>>>, param_names);
}

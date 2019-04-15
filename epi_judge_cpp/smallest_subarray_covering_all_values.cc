#include <string>
#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::string;
using std::vector;

struct Subarray {
  // Represent subarray by starting and ending indices, inclusive.
  int start, end;
};

Subarray FindSmallestSequentiallyCoveringSubset(
    const vector<string>& paragraph, const vector<string>& keywords) {
  Subarray shortest{-1, (int)paragraph.size()+1};
  // last found subarray terminating in corresponding keyword
  vector<Subarray> partials(keywords.size(), {-1, -1});
  std::unordered_map<string, int> index;
  for (int i=0; i<keywords.size(); ++i)
    index.insert({keywords[i], i});

  for (int i=0; i<paragraph.size(); ++i) {
    auto it = index.find(paragraph[i]);
    if (it == index.end())
      continue;
    int j = it->second; // keyword index

    if (j == 0)
      partials[j].start = partials[j].end = i;
    else
    if (partials[j-1].start >= 0)
    {
      Subarray cand = {partials[j-1].start, i};
      if (partials[j-1].start > partials[j].start)
        partials[j] = cand;

      if (j == partials.size()-1 && 
        (cand.end - cand.start < shortest.end - shortest.start))
          shortest = cand;
    }
  }
  return shortest;
}
int FindSmallestSequentiallyCoveringSubsetWrapper(
    TimedExecutor& executor, const vector<string>& paragraph,
    const vector<string>& keywords) {
  auto result = executor.Run([&] {
    return FindSmallestSequentiallyCoveringSubset(paragraph, keywords);
  });

  int kw_idx = 0;
  if (result.start < 0) {
    throw TestFailure("Subarray start index is negative");
  }
  int para_idx = result.start;

  while (kw_idx < keywords.size()) {
    if (para_idx >= paragraph.size()) {
      throw TestFailure("Not all keywords are in the generated subarray");
    }
    if (para_idx >= paragraph.size()) {
      throw TestFailure("Subarray end index exceeds array size");
    }
    if (paragraph[para_idx] == keywords[kw_idx]) {
      kw_idx++;
    }
    para_idx++;
  }
  return result.end - result.start + 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "paragraph", "keywords"};
  return GenericTestMain(args, "smallest_subarray_covering_all_values.cc",
                         "smallest_subarray_covering_all_values.tsv",
                         &FindSmallestSequentiallyCoveringSubsetWrapper,
                         DefaultComparator{}, param_names);
}

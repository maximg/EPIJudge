#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::string;
using std::vector;
namespace huffman {

struct CharWithFrequency {
  char c;
  double freq;
};

struct Node {
  double w;
  char c;
  Node *l, *r;
};

double averageLength(Node* n, int depth) {
  if (!n->l && !n->r) return depth * n->w;
  return averageLength(n->l, depth+1) + averageLength(n->r, depth+1);
}
double HuffmanEncoding(vector<CharWithFrequency>* symbols) {
  auto comp = [](auto a, auto b) {
    return a->w > b->w;
  };
  std::priority_queue<Node*, vector<Node*>, decltype(comp)> pq(comp);
  for (const auto& s: *symbols) pq.push(new Node{s.freq, s.c, nullptr, nullptr});
  while (pq.size() > 1) {
    Node* l = pq.top(); pq.pop();
    Node* r = pq.top(); pq.pop();
    Node* n = new Node{l->w + r->w, '*', l, r};
    pq.push(n);
  }
  // auto freqSum = 0.0;
  // for (const auto& s: *symbols) freqSum += s.freq;
  return averageLength(pq.top(), 0) / 100.0;  // looks like freqs are in %
}
}  // namespace huffman
template <>
struct SerializationTraits<huffman::CharWithFrequency>
    : UserSerTraits<huffman::CharWithFrequency, std::string, double> {
  static huffman::CharWithFrequency FromTuple(
      const std::tuple<std::string, double>& values) {
    if (std::get<0>(values).size() != 1) {
      throw std::runtime_error(
          "CharWithFrequency parser: string length is not 1");
    }
    return huffman::CharWithFrequency{std::get<0>(values)[0],
                                      std::get<1>(values)};
  }
};

double HuffmanEncodingWrapper(vector<huffman::CharWithFrequency> symbols) {
  return huffman::HuffmanEncoding(&symbols);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"symbols"};
  return GenericTestMain(args, "huffman_coding.cc", "huffman_coding.tsv",
                         &HuffmanEncodingWrapper, DefaultComparator{},
                         param_names);
}

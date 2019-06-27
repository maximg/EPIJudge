#include <vector>
#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;
using namespace std;

struct HighwaySection {
  int x, y, distance;
};

HighwaySection FindBestProposals(const vector<HighwaySection>& H,
                                 const vector<HighwaySection>& P, int n) {

    vector<vector<HighwaySection>> G;
    vector<vector<HighwaySection>> Prop;
    for (auto& s: H) {
      G.resize(std::max(s.x, s.y)+1);
      G[s.x].emplace_back(s);
      G[s.y].emplace_back(HighwaySection{s.y, s.x, s.distance});
    }
    for (auto& s: P) {
      Prop.resize(std::max(s.x, s.y)+1);
      Prop[s.x].emplace_back(s);
      Prop[s.y].emplace_back(HighwaySection{s.y, s.x, s.distance});
    }

    // Dijsktra
    int N = G.size();
    vector<bool> seenG(N);
    vector<bool> seenP(N);
    vector<HighwaySection> bestP(N);  // best proposed section to reach node N
    vector<int> bestDistG(N, INT_MAX);
    vector<int> bestDistProp(N, INT_MAX);

    int v = 0;
    bestDistG[v] = 0;
    seenP[v] = true;
    while (!seenG[v] || !seenP[v]) {

        seenG[v] = true;
        for (const auto& s: G[v]) {
            if (!seenG[s.y] && bestDistG[s.y] < bestDistG[v] + s.distance) {

                bestDistG[s.y] = bestDistG[v] + s.distance;
            }
        }
        for (const auto& s: Prop[v]) {
            if (!seenG[s.y] && bestDistG[s.y] < bestDistG[v] + s.distance) {

                bestDistG[s.y] = bestDistG[v] + s.distance;
            }
        }

        v = 1;
        int currEarliest = std::numeric_limits<int>::max();
        for (int i=0; i < N; ++i) {
            if (!seen[i] && currEarliest > arrTime[i]) {
                currEarliest = arrTime[i];
                v = i;
            }
        }
    }

  // TODO - you fill in here.
  return bestP[n];
}
template <>
struct SerializationTraits<HighwaySection>
    : UserSerTraits<HighwaySection, int, int, int> {};

bool operator==(const HighwaySection& lhs, const HighwaySection& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.distance == rhs.distance;
}

std::ostream& operator<<(std::ostream& out, const HighwaySection& hs) {
  return PrintTo(out, std::make_tuple(hs.x, hs.y, hs.distance));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"H", "P", "n"};
  return GenericTestMain(args, "road_network.cc", "road_network.tsv",
                         &FindBestProposals, DefaultComparator{}, param_names);
}

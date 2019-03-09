
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to;    // idx of the edge target
    int start;
    int dur;
};

struct Vertex {
    vector<Edge> edges;
};


int minSchedule(vector<Vertex>& g, int start_time, int from, int to) {
    vector<int> cost(g.size(), INT_MAX);
    cost[from] = start_time;

    using VertexInfo = pair<int, int>;  // cost, idx
    auto cmp = [](const VertexInfo& a, const VertexInfo& b){
        return a.first > b.first;
    };
    priority_queue<VertexInfo, vector<VertexInfo>, decltype(cmp)> dijkstra(cmp);

    dijkstra.push({start_time, from});
    while (!dijkstra.empty()) {
        auto info = dijkstra.top();
        dijkstra.pop();
        for (auto e: g[info.second].edges) {
            if (e.start > info.first) {
                int new_cost = e.start + e.dur + 60;
                if (new_cost < cost[e.to]) {
                    cost[e.to] = new_cost;
                    dijkstra.push({new_cost, e.to});
                }
            }
        }
    }

    return cost[to] - start_time - 60;
}

int main() {

    vector<Vertex> g = {
        Vertex{ {{ 1, 100, 200 }, { 2, 200, 120 }} },
        Vertex{ {{ 2, 400, 50  }, { 3, 450, 100 }} },
        Vertex{ {{ 3, 400, 100 }} },
        Vertex{}
    };

    cout << minSchedule(g, 0, 0, 3) << endl;
}
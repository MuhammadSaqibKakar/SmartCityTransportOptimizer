#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<int> dijkstra(int n, int start, vector<vector<Edge>>& graph) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto& e : graph[u]) {
            if (dist[e.to] > d + e.weight) {
                dist[e.to] = d + e.weight;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

// Simulate dynamic traffic (randomly change some weights)
void updateTraffic(vector<vector<Edge>>& graph) {
    srand(time(0));
    for (auto& edges : graph) {
        for (auto& e : edges) {
            int change = (rand() % 11) - 5; // -5 to +5 change
            e.weight = max(1, e.weight + change);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<Edge>> graph(n);
    graph[0] = {{1, 10}, {2, 3}};
    graph[1] = {{2, 1}, {3, 2}};
    graph[2] = {{1, 4}, {3, 8}, {4, 2}};
    graph[3] = {{4, 7}};
    graph[4] = {{3, 9}};

    ofstream file("../../data/dynamic_routing.csv");
    file << "Round,Node,Distance\n";

    for (int round = 1; round <= 3; ++round) {
        cout << "Running Dijkstra for traffic round " << round << "...\n";
        vector<int> distances = dijkstra(n, 0, graph);
        for (int i = 0; i < n; i++) {
            file << round << "," << i << "," << distances[i] << "\n";
        }
        updateTraffic(graph); // simulate traffic change
    }

    file.close();
    cout << "✅ Dynamic routing results saved to data/dynamic_routing.csv\n";
    return 0;
}

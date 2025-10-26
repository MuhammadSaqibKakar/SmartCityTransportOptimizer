#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <limits>
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

int main() {
    int n = 5;
    vector<vector<Edge>> graph(n);

    graph[0] = {{1, 10}, {2, 3}};
    graph[1] = {{2, 1}, {3, 2}};
    graph[2] = {{1, 4}, {3, 8}, {4, 2}};
    graph[3] = {{4, 7}};
    graph[4] = {{3, 9}};

    vector<int> distances = dijkstra(n, 0, graph);

    ofstream file("../../data/dijkstra_output.csv");
    file << "Node,Distance\n";
    for (int i = 0; i < n; i++) {
        file << i << "," << distances[i] << "\n";
    }
    file.close();

    cout << "Dijkstra completed. Results saved to data/dijkstra_output.csv\n";
    return 0;
}

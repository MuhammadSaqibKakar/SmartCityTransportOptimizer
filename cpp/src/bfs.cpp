#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

vector<int> bfs(int n, vector<vector<int>>& adj, int start) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {1, 3, 4};
    adj[3] = {4};
    adj[4] = {3};

    vector<int> distances = bfs(n, adj, 0);

    ofstream file("../../data/bfs_output.csv");
    file << "Node,Distance\n";
    for (int i = 0; i < n; i++) {
        file << i << "," << distances[i] << "\n";
    }
    file.close();

    cout << "BFS completed. Results saved to data/bfs_output.csv\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void dfsUtil(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order) {
    visited[u] = true;
    order.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v])
            dfsUtil(v, adj, visited, order);
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {1, 3, 4};
    adj[3] = {4};
    adj[4] = {3};

    vector<bool> visited(n, false);
    vector<int> order;
    dfsUtil(0, adj, visited, order);

    ofstream file("../../data/dfs_output.csv");
    file << "Visit_Order\n";
    for (int node : order) {
        file << node << "\n";
    }
    file.close();

    cout << "DFS completed. Results saved to data/dfs_output.csv\n";
    return 0;
}

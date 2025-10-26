#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

// Greedy: assign nearest available vehicle to each route
vector<int> greedyAssignment(vector<vector<int>>& costMatrix) {
    int n = costMatrix.size(); // vehicles
    int m = costMatrix[0].size(); // routes
    vector<int> assignedRoute(n, -1);
    vector<bool> routeTaken(m, false);

    for (int v = 0; v < n; v++) {
        int minCost = INT_MAX, bestRoute = -1;
        for (int r = 0; r < m; r++) {
            if (!routeTaken[r] && costMatrix[v][r] < minCost) {
                minCost = costMatrix[v][r];
                bestRoute = r;
            }
        }
        if (bestRoute != -1) {
            assignedRoute[v] = bestRoute;
            routeTaken[bestRoute] = true;
        }
    }
    return assignedRoute;
}

// Dynamic Programming (assignment problem) — simplified bitmask DP
int dpAssignment(vector<vector<int>>& cost, int i, int mask, vector<vector<int>>& dp) {
    int n = cost.size();
    if (i == n) return 0;
    if (dp[i][mask] != -1) return dp[i][mask];
    int ans = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (!(mask & (1 << j))) {
            ans = min(ans, cost[i][j] + dpAssignment(cost, i + 1, mask | (1 << j), dp));
        }
    }
    return dp[i][mask] = ans;
}

int main() {
    // Cost matrix: vehicles × routes (lower cost = more efficient)
    vector<vector<int>> cost = {
        {8, 7, 9, 6},
        {5, 9, 7, 8},
        {6, 4, 3, 7},
        {9, 8, 6, 5}
    };

    // Greedy result
    vector<int> greedyRes = greedyAssignment(cost);

    // DP result
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>((1 << n), -1));
    int dpCost = dpAssignment(cost, 0, 0, dp);

    // Save results
    ofstream file("../../data/vehicle_scheduling.csv");
    file << "Vehicle,Greedy_Assigned_Route\n";
    for (int i = 0; i < greedyRes.size(); i++)
        file << i << "," << greedyRes[i] << "\n";
    file << "\nTotal_Optimal_Cost(DP):," << dpCost << "\n";
    file.close();

    cout << "✅ Vehicle scheduling results saved to data/vehicle_scheduling.csv\n";
    return 0;
}

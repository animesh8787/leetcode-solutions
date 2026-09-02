// Critical Connections in a Network
// Difficulty: Hard   Solved: 2026-09-02
// https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n, -1), low(n, -1);
        vector<vector<int>> ans;
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int parent) {
            tin[u] = low[u] = timer++;

            for (int v : adj[u]) {
                if (v == parent)
                    continue;

                if (tin[v] != -1) {
                    low[u] = min(low[u], tin[v]);
                } else {
                    dfs(v, u);

                    low[u] = min(low[u], low[v]);

                    if (low[v] > tin[u])
                        ans.push_back({u, v});
                }
            }
        };

        dfs(0, -1);

        return ans;
    }
};

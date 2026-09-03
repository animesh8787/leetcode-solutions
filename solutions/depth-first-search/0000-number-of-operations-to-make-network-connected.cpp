// Number of Operations to Make Network Connected
// Difficulty: Medium   Solved: 2026-09-03
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return;

            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;
        };

        for (auto &edge : connections)
            unite(edge[0], edge[1]);

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        return components - 1;
    }
};

// Most Stones Removed with Same Row or Column
// Difficulty: Medium   Solved: 2026-09-03
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

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

        unordered_map<int, int> row, col;

        for (int i = 0; i < n; i++) {
            int x = stones[i][0];
            int y = stones[i][1];

            if (row.count(x))
                unite(i, row[x]);
            else
                row[x] = i;

            if (col.count(y))
                unite(i, col[y]);
            else
                col[y] = i;
        }

        unordered_set<int> components;

        for (int i = 0; i < n; i++)
            components.insert(find(i));

        return n - components.size();
    }
};

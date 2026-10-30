// Shortest Path With At Most K Consecutive Identical Characters
// Difficulty: Medium   Solved: 2026-10-30
// https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
    if (n == 1) return 0;

    vector<vector<pair<int,int>>> adj(n);
    for (auto &e : edges) adj[e[0]].push_back({e[1], e[2]});

    const long long INF = LLONG_MAX;
    vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));
    priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> pq;

    dist[0][1] = 0;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        auto [d, u, r] = pq.top(); pq.pop();
        if (d > dist[u][r]) continue;
        for (auto &[v, w] : adj[u]) {
            int nr = (labels[v] == labels[u]) ? r + 1 : 1;
            if (nr > k) continue;
            long long nd = d + w;
            if (nd < dist[v][nr]) {
                dist[v][nr] = nd;
                pq.push({nd, v, nr});
            }
        }
    }

    long long ans = INF;
    for (int r = 1; r <= k; r++) ans = min(ans, dist[n - 1][r]);
    return ans == INF ? -1 : (int)ans;
}
};

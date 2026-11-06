// Count Zero Request Servers
// Difficulty: Medium   Solved: 2026-11-06
// https://leetcode.com/problems/count-zero-request-servers/

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> cnt(n + 1, 0);
        int activeServers = 0; // servers with cnt > 0
        int right = 0, left = 0;
        int m = logs.size();

        vector<int> ans(q);

        for (int idx : order) {
            int query = queries[idx];
            long long lo = (long long)query - x;
            long long hi = query;

            // add logs with time <= hi
            while (right < m && logs[right][1] <= hi) {
                int sid = logs[right][0];
                if (cnt[sid] == 0) activeServers++;
                cnt[sid]++;
                right++;
            }
            // remove logs with time < lo
            while (left < m && logs[left][1] < lo) {
                int sid = logs[left][0];
                cnt[sid]--;
                if (cnt[sid] == 0) activeServers--;
                left++;
            }

            ans[idx] = n - activeServers;
        }

        return ans;
    }
};

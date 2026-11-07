// Process Tasks Using Servers
// Difficulty: Unknown   Solved: 2026-11-07
// https://leetcode.com/problems/process-tasks-using-servers/

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        // free servers: (weight, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeHeap;
        // busy servers: (freeTime, weight, index)
        priority_queue<array<long long,3>, vector<array<long long,3>>, greater<>> busyHeap;

        for (int i = 0; i < n; i++) freeHeap.push({servers[i], i});

        vector<int> ans(m);
        long long clock = 0; // latest resolved real time

        for (int j = 0; j < m; j++) {
            long long curTime = max((long long)j, clock);

            // release servers free by curTime
            while (!busyHeap.empty() && busyHeap.top()[0] <= curTime) {
                auto top = busyHeap.top(); busyHeap.pop();
                freeHeap.push({(int)top[1], (int)top[2]});
            }

            // if still none free, fast-forward to the next completion
            if (freeHeap.empty()) {
                curTime = busyHeap.top()[0];
                while (!busyHeap.empty() && busyHeap.top()[0] <= curTime) {
                    auto top = busyHeap.top(); busyHeap.pop();
                    freeHeap.push({(int)top[1], (int)top[2]});
                }
            }

            clock = curTime; // remember how far time has actually advanced

            auto [w, idx] = freeHeap.top(); freeHeap.pop();
            ans[j] = idx;
            busyHeap.push({curTime + tasks[j], w, idx});
        }

        return ans;
    }
};

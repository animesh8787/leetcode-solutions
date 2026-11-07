// Process Tasks Using Servers
// Difficulty: Medium   Solved: 2026-11-07
// https://leetcode.com/problems/process-tasks-using-servers/

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        // free: (weight, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeHeap;
        // busy: (freeTime, weight, index)
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> busyHeap;

        for (int i = 0; i < n; i++) freeHeap.push({servers[i], i});

        vector<int> ans(m);

        for (int j = 0; j < m; j++) {
            long long curTime = j;

            // release all servers free by curTime
            while (!busyHeap.empty() && get<0>(busyHeap.top()) <= curTime) {
                auto [ft, w, idx] = busyHeap.top();
                busyHeap.pop();
                freeHeap.push({w, idx});
            }

            if (freeHeap.empty()) {
                // must wait until the earliest busy server frees up
                auto [ft, w, idx] = busyHeap.top();
                busyHeap.pop();
                curTime = ft;
                freeHeap.push({w, idx});
                // release any others freeing at the same time
                while (!busyHeap.empty() && get<0>(busyHeap.top()) <= curTime) {
                    auto [ft2, w2, idx2] = busyHeap.top();
                    busyHeap.pop();
                    freeHeap.push({w2, idx2});
                }
            }

            auto [w, idx] = freeHeap.top();
            freeHeap.pop();
            ans[j] = idx;
            busyHeap.push({curTime + tasks[j], w, idx});
        }

        return ans;
    }
};

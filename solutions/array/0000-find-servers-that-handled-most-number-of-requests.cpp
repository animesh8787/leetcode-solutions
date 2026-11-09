// Find Servers That Handled Most Number of Requests
// Difficulty: Hard   Solved: 2026-11-09
// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; i++) available.insert(i);

        // busy: (endTime, serverId)
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;

        vector<int> count(k, 0);
        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            long long curArrival = arrival[i];

            // free up servers that finished by curArrival
            while (!busy.empty() && busy.top().first <= curArrival) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) continue; // dropped

            int start = i % k;
            auto it = available.lower_bound(start);
            if (it == available.end()) {
                it = available.begin(); // wrap around
            }

            int server = *it;
            available.erase(it);
            count[server]++;
            busy.push({curArrival + load[i], server});
        }

        int maxCount = *max_element(count.begin(), count.end());
        vector<int> ans;
        for (int s = 0; s < k; s++) {
            if (count[s] == maxCount) ans.push_back(s);
        }
        return ans;
    }
};

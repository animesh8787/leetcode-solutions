// Frequency of the Most Frequent Element
// Difficulty: Medium   Solved: 2026-10-14
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int x : nums) freq[x]++;

        vector<pair<int,int>> v(freq.begin(), freq.end()); // sorted (value, count)

        long long sum = 0, cnt = 0;
        int l = 0;
        long long best = 0;
        for (int r = 0; r < v.size(); r++) {
            sum += (long long)v[r].first * v[r].second;
            cnt += v[r].second;

            // shrink while the whole window is too expensive
            while ((long long)v[r].first * cnt - sum > k) {
                sum -= (long long)v[l].first * v[l].second;
                cnt -= v[l].second;
                l++;
            }

            // Window [l..r] fits. Also try taking only part of v[l-1]:
            // each extra copy of v[l-1] costs (v[r] - v[l-1]).
            long long cur = cnt;
            if (l > 0) {
                long long left = k - (v[r].first * cnt - sum);
                long long diff = v[r].first - v[l-1].first;
                cur += min((long long)v[l-1].second, left / diff);
            }
            best = max(best, cur);
        }
        return best;
    }
};

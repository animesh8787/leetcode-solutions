// Partition Array Into Two Arrays to Minimize Sum Difference
// Difficulty: Hard   Solved: 2026-09-04
// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[i];
                }
            }
            left[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[n + i];
                }
            }
            right[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        long long ans = LLONG_MAX;

        for (int cnt = 0; cnt <= n; cnt++) {
            for (int sum1 : left[cnt]) {
                int need = n - cnt;
                auto &v = right[need];

                int target = total / 2 - sum1;
                auto it = lower_bound(v.begin(), v.end(), target);

                if (it != v.end()) {
                    long long sumA = sum1 + *it;
                    ans = min(ans, llabs(total - 2 * sumA));
                }

                if (it != v.begin()) {
                    --it;
                    long long sumA = sum1 + *it;
                    ans = min(ans, llabs(total - 2 * sumA));
                }
            }
        }

        return (int)ans;
    }
};

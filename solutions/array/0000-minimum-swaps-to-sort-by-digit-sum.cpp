// Minimum Swaps to Sort by Digit Sum
// Difficulty: Medium   Solved: 2026-10-17
// https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/

class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Step 1: sorted target order by (digit sum, value)
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end(), [&](int a, int b) {
            int sa = digitSum(a), sb = digitSum(b);
            if (sa != sb) return sa < sb;
            return a < b;
        });

        // Step 2: value -> its target index
        unordered_map<int, int> targetIndex;
        for (int i = 0; i < n; i++) {
            targetIndex[sorted_nums[i]] = i;
        }

        // Step 3: count swaps via cycles
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || targetIndex[nums[i]] == i) {
                visited[i] = true;
                continue;
            }
            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = targetIndex[nums[j]];
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }
        return swaps;
    }
};

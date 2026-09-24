// Smallest Index With Digit Sum Equal to Index
// Difficulty: Easy   Solved: 2026-09-24
// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            if (sum == i)
                return i;
        }

        return -1;
    }
};

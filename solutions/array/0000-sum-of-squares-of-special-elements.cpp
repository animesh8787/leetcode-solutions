// Sum of Squares of Special Elements
// Difficulty: Easy   Solved: 2026-10-11
// https://leetcode.com/problems/sum-of-squares-of-special-elements/

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += nums[i - 1] * nums[i - 1];
            }
        }

        return sum;
    }
};

// Minimum Moves to Equal Array Elements II
// Difficulty: Medium   Solved: 2026-11-02
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        long long moves = 0;
        for (int x : nums) moves += abs((long long)x - median);
        return (int)moves;
    }
};

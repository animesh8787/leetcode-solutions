// Minimum Moves to Equal Array Elements
// Difficulty: Medium   Solved: 2026-11-01
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long minVal = *min_element(nums.begin(), nums.end());
        long long moves = 0;
        for (int x : nums) moves += (x - minVal);
        return (int)moves;
    }
};

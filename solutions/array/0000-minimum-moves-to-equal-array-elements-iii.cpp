// Minimum Moves to Equal Array Elements III
// Difficulty: Easy   Solved: 2026-11-03
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for (int x : nums) moves += (maxVal - x);
        return moves;
    }
};

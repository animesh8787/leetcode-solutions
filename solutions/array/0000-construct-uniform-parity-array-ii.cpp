// Construct Uniform Parity Array II
// Difficulty: Medium   Solved: 2026-09-03
// https://leetcode.com/problems/construct-uniform-parity-array-ii/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x & 1)
                minOdd = min(minOdd, x);
            else
                minEven = min(minEven, x);
        }

        if (minOdd == INT_MAX)
            return true;

        if (minEven == INT_MAX)
            return true;

        return minOdd < minEven;
    }
};

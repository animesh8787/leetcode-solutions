// Reverse Degree of a String
// Difficulty: Easy   Solved: 2026-09-20
// https://leetcode.com/problems/reverse-degree-of-a-string/

class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int value = 'z' - s[i] + 1;
            ans += value * (i + 1);
        }

        return ans;
    }
};

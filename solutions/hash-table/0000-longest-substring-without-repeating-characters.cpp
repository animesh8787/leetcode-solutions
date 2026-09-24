// Longest Substring Without Repeating Characters
// Difficulty: Medium   Solved: 2026-09-24
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); ++right) {
            left = max(left, last[(unsigned char)s[right]] + 1);
            last[(unsigned char)s[right]] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

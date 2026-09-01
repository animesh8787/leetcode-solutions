// Find the Index of the First Occurrence in a String
// Difficulty: Unknown   Solved: 2026-09-01
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && haystack[i + j] == needle[j])
                j++;

            if (j == m)
                return i;
        }

        return -1;
    }
};

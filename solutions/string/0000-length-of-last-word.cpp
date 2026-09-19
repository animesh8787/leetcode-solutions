// Length of Last Word
// Difficulty: Easy   Solved: 2026-09-19
// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        
        while (i >= 0 && s[i] == ' ')
            i--;
        
        int len = 0;
        
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        
        return len;
    }
};

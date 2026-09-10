// Repeated String Match
// Difficulty: Medium   Solved: 2026-09-10
// https://leetcode.com/problems/repeated-string-match/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s;
        int count = 0;

        while (s.size() < b.size()) {
            s += a;
            count++;
        }

        if (s.find(b) != string::npos)
            return count;

        s += a;

        if (s.find(b) != string::npos)
            return count + 1;

        return -1;
    }
};

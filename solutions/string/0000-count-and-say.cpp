// Count and Say
// Difficulty: Medium   Solved: 2026-09-10
// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string next;

            for (int j = 0; j < s.size();) {
                int k = j;

                while (k < s.size() && s[k] == s[j])
                    k++;

                next += to_string(k - j);
                next += s[j];

                j = k;
            }

            s = next;
        }

        return s;
    }
};

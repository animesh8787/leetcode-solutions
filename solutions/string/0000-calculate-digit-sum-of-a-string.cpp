// Calculate Digit Sum of a String
// Difficulty: Easy   Solved: 2026-11-16
// https://leetcode.com/problems/calculate-digit-sum-of-a-string/

class Solution {
public:
    string digitSum(string s, int k) {
        while ((int)s.size() > k) {
            string next;
            for (int i = 0; i < (int)s.size(); i += k) {
                int sum = 0;
                for (int j = i; j < i + k && j < (int)s.size(); j++) {
                    sum += s[j] - '0';
                }
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};

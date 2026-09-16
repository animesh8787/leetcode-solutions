// Multiply Strings
// Difficulty: Medium   Solved: 2026-09-16
// https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int pos = i + j + 1;
                int sum = a * b + res[pos];

                res[pos] = sum % 10;
                res[pos - 1] += sum / 10;
            }
        }

        string ans;
        int i = 0;

        while (i < res.size() && res[i] == 0)
            i++;

        while (i < res.size())
            ans += char(res[i++] + '0');

        return ans;
    }
};

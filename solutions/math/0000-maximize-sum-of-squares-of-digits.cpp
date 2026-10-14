// Maximize Sum of Squares of Digits
// Difficulty: Medium   Solved: 2026-10-14
// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        int nines = sum / 9;
        int rem = sum % 9;
        string result;
        result.reserve(num);
        result.append(nines, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        result.append(num - result.size(), '0');
        return result;
    }
};

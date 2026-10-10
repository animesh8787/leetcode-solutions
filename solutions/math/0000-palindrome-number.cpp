// Palindrome Number
// Difficulty: Easy   Solved: 2026-10-10
// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int n = x;
        long long pal = 0;

        while (x > 0) {
            int ld = x % 10;
            pal = (pal * 10) + ld;
            x /= 10;
        }

        return pal == n;
    }
};

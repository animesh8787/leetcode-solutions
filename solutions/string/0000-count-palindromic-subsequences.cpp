// Count Palindromic Subsequences
// Difficulty: Hard   Solved: 2026-09-10
// https://leetcode.com/problems/count-palindromic-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        if (n < 5) return 0;
        const long long MOD = 1000000007;
        vector<int> d(n);
        for (int i = 0; i < n; i++) d[i] = s[i] - '0';

        vector<array<array<int,10>,10>> right(n + 1);
        for (auto &m : right) for (auto &row : m) row.fill(0);

        array<int,10> cntSuffix{};
        for (int k = n - 1; k >= 0; k--) {
            right[k] = right[k + 1];
            int dig = d[k];
            for (int a = 0; a < 10; a++) {
                right[k][dig][a] += cntSuffix[a];
            }
            cntSuffix[dig]++;
        }

        array<array<int,10>,10> leftMatrix{};
        array<int,10> cntPrefix{};
        long long ans = 0;

        for (int c = 0; c < n; c++) {
            auto &R = right[c + 1];
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    if (leftMatrix[a][b] == 0) continue;
                    long long prod = (long long)leftMatrix[a][b] * R[b][a];
                    ans = (ans + prod) % MOD;
                }
            }
            int dig = d[c];
            for (int x = 0; x < 10; x++) {
                leftMatrix[x][dig] += cntPrefix[x];
            }
            cntPrefix[dig]++;
        }

        return (int)(ans % MOD);
    }
};

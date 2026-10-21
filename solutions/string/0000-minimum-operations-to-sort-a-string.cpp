// Minimum Operations to Sort a String
// Difficulty: Medium   Solved: 2026-10-21
// https://leetcode.com/problems/minimum-operations-to-sort-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] > s[i + 1]) { sorted = false; break; }
        }
        if (sorted) return 0;
        if (n == 2) return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[n - 1] == mx) return 1;
        int cntMax = (int)count(s.begin(), s.end(), mx);
        int cntMin = (int)count(s.begin(), s.end(), mn);
        bool bad = (s[0] == mx && cntMax == 1) && (s[n - 1] == mn && cntMin == 1);
        return bad ? 3 : 2;
    }
};

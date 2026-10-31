// Twisted Mirror Path Count
// Difficulty: Medium   Solved: 2026-10-31
// https://leetcode.com/problems/twisted-mirror-path-count/

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        const int OOB = -1;
        auto idx = [&](int r, int c) { return r * n + c; };

        vector<vector<int>> landR(m, vector<int>(n)), landD(m, vector<int>(n));

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                // right move
                int nc = c + 1;
                if (nc >= n) landR[r][c] = OOB;
                else if (grid[r][nc] == 0) landR[r][c] = idx(r, nc);
                else landR[r][c] = landD[r][nc];

                // down move
                int nr = r + 1;
                if (nr >= m) landD[r][c] = OOB;
                else if (grid[nr][c] == 0) landD[r][c] = idx(nr, c);
                else landD[r][c] = landR[nr][c];
            }
        }

        vector<long long> dp(m * n, 0);
        dp[idx(0, 0)] = 1;

        for (int s = 0; s <= m + n - 2; s++) {
            int rLo = max(0, s - (n - 1)), rHi = min(m - 1, s);
            for (int r = rLo; r <= rHi; r++) {
                int c = s - r;
                if (grid[r][c] != 0) continue;       // robot never rests on a mirror
                long long cur = dp[idx(r, c)];
                if (cur == 0) continue;
                int lr = landR[r][c];
                if (lr != OOB) dp[lr] = (dp[lr] + cur) % MOD;
                int ld = landD[r][c];
                if (ld != OOB) dp[ld] = (dp[ld] + cur) % MOD;
            }
        }

        return (int)(dp[idx(m - 1, n - 1)] % MOD);
    }
};

// Minimum XOR Path in a Grid
// Difficulty: Medium   Solved: 2026-10-28
// https://leetcode.com/problems/minimum-xor-path-in-a-grid/

class Solution {
public:

int minCost(vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size();
    vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
    dp[0][0].set(grid[0][0]);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            bitset<1024> prev;
            if(i > 0) prev |= dp[i-1][j];
            if(j > 0) prev |= dp[i][j-1];

            int val = grid[i][j];
            bitset<1024> cur;
            for(int k = 0; k < 1024; k++)
                if(prev[k]) cur.set(k ^ val);
            dp[i][j] = cur;
        }
    }

    for(int k = 0; k < 1024; k++)
        if(dp[m-1][n-1][k]) return k;
    return -1;
}
};

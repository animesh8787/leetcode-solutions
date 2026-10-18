// Number of Ways to Reorder Array to Get Same BST
// Difficulty: Hard   Solved: 2026-10-18
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> C;

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Pascal's triangle for binomial coefficients mod MOD
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        // Returns {ways, subtree size} for the subtree built from vals
        function<pair<long long,int>(const vector<int>&)> solve =
            [&](const vector<int>& vals) -> pair<long long,int> {
            if (vals.empty()) return {1, 0};

            int root = vals[0];
            vector<int> left, right;
            for (int i = 1; i < (int)vals.size(); i++) {
                if (vals[i] < root) left.push_back(vals[i]);
                else right.push_back(vals[i]);
            }

            auto [wl, nl] = solve(left);
            auto [wr, nr] = solve(right);

            long long ways = C[nl + nr][nl];
            ways = ways * wl % MOD;
            ways = ways * wr % MOD;
            return {ways, nl + nr + 1};
        };

        return (solve(nums).first - 1 + MOD) % MOD;
    }
};

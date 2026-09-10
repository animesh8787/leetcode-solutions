// Maximum XOR With an Element From Array
// Difficulty: Hard   Solved: 2026-09-10
// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

class Solution {
public:
    struct TrieNode {
        int child[2];
        TrieNode() {
            child[0] = child[1] = -1;
        }
    };

    vector<TrieNode> trie;

    void insert(int num) {
        int node = 0;

        for (int b = 30; b >= 0; b--) {
            int bit = (num >> b) & 1;

            if (trie[node].child[bit] == -1) {
                trie[node].child[bit] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].child[bit];
        }
    }

    int getMaxXor(int num) {
        int node = 0;
        int ans = 0;

        for (int b = 30; b >= 0; b--) {
            int bit = (num >> b) & 1;
            int want = bit ^ 1;

            if (trie[node].child[want] != -1) {
                ans |= (1 << b);
                node = trie[node].child[want];
            } else {
                node = trie[node].child[bit];
            }
        }

        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<array<int, 3>> q;

        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i][1], queries[i][0], i});

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        trie.clear();
        trie.emplace_back();

        int j = 0;

        for (auto [m, x, idx] : q) {
            while (j < nums.size() && nums[j] <= m) {
                insert(nums[j]);
                j++;
            }

            if (j == 0)
                ans[idx] = -1;
            else
                ans[idx] = getMaxXor(x);
        }

        return ans;
    }
};

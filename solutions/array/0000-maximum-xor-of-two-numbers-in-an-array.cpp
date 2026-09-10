// Maximum XOR of Two Numbers in an Array
// Difficulty: Medium   Solved: 2026-09-10
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class Solution {
public:
    struct Node {
        int child[2] = {-1, -1};
    };

    vector<Node> trie;

    void insert(int x) {
        int node = 0;

        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;

            if (trie[node].child[bit] == -1) {
                trie[node].child[bit] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[bit];
        }
    }

    int query(int x) {
        int node = 0;
        int ans = 0;

        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;
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

    int findMaximumXOR(vector<int>& nums) {
        trie.clear();
        trie.push_back(Node());

        int ans = 0;

        for (int x : nums) {
            insert(x);
            ans = max(ans, query(x));
        }

        return ans;
    }
};

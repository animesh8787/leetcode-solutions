// Find Subtree Sizes After Changes
// Difficulty: Medium   Solved: 2026-11-21
// https://leetcode.com/problems/find-subtree-sizes-after-changes/

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newParent(n, -1);
        vector<int> order;
        order.reserve(n);
        int last[26];
        for (int c = 0; c < 26; c++) last[c] = -1;

        vector<int> saved(n, -1);
        vector<pair<int,int>> st;
        st.push_back({0, 0});
        while (!st.empty()) {
            auto& [x, idx] = st.back();
            if (idx == 0) {
                order.push_back(x);
                int c = s[x] - 'a';
                if (x != 0) {
                    newParent[x] = (last[c] != -1) ? last[c] : parent[x];
                }
                saved[x] = last[c];
                last[c] = x;
            }
            if (idx < (int)children[x].size()) {
                int child = children[x][idx];
                idx++;
                st.push_back({child, 0});
            } else {
                last[s[x] - 'a'] = saved[x];
                st.pop_back();
            }
        }

        vector<int> size(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int x = order[i];
            size[newParent[x]] += size[x];
        }
        return size;
    }
};

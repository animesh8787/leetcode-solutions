// Simplify Path
// Difficulty: Medium   Solved: 2026-10-03
// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (cur == "..") {
                    if (!st.empty())
                        st.pop_back();
                } else if (!cur.empty() && cur != ".") {
                    st.push_back(cur);
                }
                cur.clear();
            } else {
                cur += path[i];
            }
        }

        string ans = "/";
        
        for (int i = 0; i < st.size(); i++) {
            ans += st[i];
            if (i + 1 < st.size())
                ans += "/";
        }

        return ans;
    }
};

// Brace Expansion II
// Difficulty: Hard   Solved: 2026-09-25
// https://leetcode.com/problems/brace-expansion-ii/

class Solution {
public:
    set<string> parseExpression(string& s, int& i) {
        set<string> res;

        while (i < s.size() && s[i] != '}') {
            set<string> cur = parseTerm(s, i);

            res.insert(cur.begin(), cur.end());

            if (i < s.size() && s[i] == ',')
                i++;
            else
                break;
        }

        return res;
    }

    set<string> parseTerm(string& s, int& i) {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;

            if (s[i] == '{') {
                i++;
                cur = parseExpression(s, i);
                i++;
            } else {
                cur.insert(string(1, s[i]));
                i++;
            }

            set<string> next;

            for (const string& a : res) {
                for (const string& b : cur) {
                    next.insert(a + b);
                }
            }

            res = next;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> res = parseExpression(expression, i);

        return vector<string>(res.begin(), res.end());
    }
};

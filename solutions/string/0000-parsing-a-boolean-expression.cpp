// Parsing A Boolean Expression
// Difficulty: Hard   Solved: 2026-09-09
// https://leetcode.com/problems/parsing-a-boolean-expression/

class Solution {
public:
    bool parse(string &s, int &i) {
        if (s[i] == 't') {
            i++;
            return true;
        }

        if (s[i] == 'f') {
            i++;
            return false;
        }

        char op = s[i];
        i += 2;

        if (op == '!') {
            bool val = parse(s, i);
            i++;
            return !val;
        }

        bool result = (op == '&');

        while (s[i] != ')') {
            if (s[i] == ',') {
                i++;
                continue;
            }

            bool val = parse(s, i);

            if (op == '&')
                result &= val;
            else
                result |= val;
        }

        i++;
        return result;
    }

    bool parseBoolExpr(string expression) {
        int i = 0;
        return parse(expression, i);
    }
};

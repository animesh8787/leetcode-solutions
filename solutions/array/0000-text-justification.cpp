// Text Justification
// Difficulty: Hard   Solved: 2026-09-28
// https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        
        for (int i = 0; i < n; ) {
            int j = i;
            int len = 0;
            
            while (j < n) {
                if (len + words[j].size() + (j - i) > maxWidth)
                    break;
                len += words[j].size();
                j++;
            }
            
            int gaps = j - i - 1;
            string line;
            
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i)
                        line += ' ';
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int spaces = maxWidth - len;
                int each = spaces / gaps;
                int extra = spaces % gaps;
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int cnt = each + (k - i < extra ? 1 : 0);
                        line += string(cnt, ' ');
                    }
                }
            }
            
            res.push_back(line);
            i = j;
        }
        
        return res;
    }
};

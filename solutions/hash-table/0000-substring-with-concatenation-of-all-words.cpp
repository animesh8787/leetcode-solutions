// Substring with Concatenation of All Words
// Difficulty: Hard   Solved: 2026-09-11
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen = words[0].size();
        int n = words.size();
        int totalLen = wordLen * n;

        if (totalLen > s.size()) return ans;

        unordered_map<string, int> target;
        for (auto &word : words) {
            target[word]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, right = offset, count = 0;
            unordered_map<string, int> seen;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (target.find(word) == target.end()) {
                    seen.clear();
                    count = 0;
                    left = right;
                } else {
                    seen[word]++;
                    count++;

                    while (seen[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == n) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
            }
        }

        return ans;
    }
};

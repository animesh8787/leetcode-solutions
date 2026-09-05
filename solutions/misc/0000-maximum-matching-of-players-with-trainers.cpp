// Maximum Matching of Players With Trainers
// Difficulty: Unknown   Solved: 2026-09-05
// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, ans = 0;

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return ans;
    }
};

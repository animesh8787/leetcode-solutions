// Stone Removal Game
// Difficulty: Easy   Solved: 2026-11-26
// https://leetcode.com/problems/stone-removal-game/

class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        bool alice = true;
        while (take > 0 && n >= take) {
            n -= take;
            take--;
            alice = !alice;
        }
        return !alice;
    }
};

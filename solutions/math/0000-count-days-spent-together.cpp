// Count Days Spent Together
// Difficulty: Easy   Solved: 2026-10-24
// https://leetcode.com/problems/count-days-spent-together/

class Solution {
public:
    int dayOfYear(const string& s) {
        static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));
        int total = 0;
        for (int i = 0; i < month - 1; i++) total += days[i];
        return total + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));
        return max(0, end - start + 1);
    }
};

// Find the Distance Value Between Two Arrays
// Difficulty: Easy   Solved: 2026-11-05
// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for (int a : arr1) {
            bool ok = true;
            for (int b : arr2) {
                if (abs(a - b) <= d) { ok = false; break; }
            }
            if (ok) count++;
        }
        return count;
    }
};

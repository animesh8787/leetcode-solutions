// Maximum Alternating Sum of Squares
// Difficulty: Medium   Solved: 2026-10-13
// https://leetcode.com/problems/maximum-alternating-sum-of-squares/

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        sq.reserve(nums.size());
        for (int x : nums) {
            sq.push_back((long long)x * x);
        }
        sort(sq.begin(), sq.end(), greater<long long>());
        size_t k = (sq.size() + 1) / 2;
        long long result = 0;
        for (size_t i = 0; i < sq.size(); i++) {
            if (i < k) result += sq[i];
            else result -= sq[i];
        }
        return result;
    }
};

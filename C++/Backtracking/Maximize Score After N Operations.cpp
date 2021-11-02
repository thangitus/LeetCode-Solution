#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximize-score-after-n-operations/
*/

class Solution {
private:
    int size, n;
    unordered_map<int, int> memo;
public:
    int maxScore(vector<int> &nums) {
        size = nums.size(), n = size / 2;
        return backtracking(nums, 1, 0);
    }

    int backtracking(vector<int> &nums, int op, int mask) {
        if (op > n) return 0;
        if (memo[mask]) return memo[mask];
        for (int i = 0; i < size; i++) {
            if ((mask >> i) & 1) continue;
            for (int j = i + 1; j < size; j++) {
                if ((mask >> j) & 1) continue;
                int newMask = (1 << i) | (1 << j) | mask;
                int score = op * __gcd(nums[i], nums[j]) + backtracking(nums, op + 1, newMask);
                memo[mask] = max(memo[mask], score);
            }
        }
        return memo[mask];
    }
};
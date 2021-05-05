#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/jump-game-ii/
 * */

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> jumps(n, INT_MAX);
        jumps[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= nums[i]; j++)
                if (i + j < n) jumps[i + j] = min(jumps[i + j], jumps[i] + 1);
        return jumps.back();
    }
};
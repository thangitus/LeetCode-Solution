#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/wiggle-subsequence/
 * */

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        auto n = nums.size();
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up.back(), down.back());
    }
};
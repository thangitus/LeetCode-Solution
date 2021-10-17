#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
*/

class Solution {
public:
    int maxNum = 0;
    int res = 0;

    int countMaxOrSubsets(vector<int> &nums) {
        for (int &num:nums) maxNum |= num;
        backtracking(nums, 0, 0);
        return res;
    }

    void backtracking(vector<int> &nums, int i, int num) {
        if (i == nums.size()) {
            if (num == maxNum) res++;
            return;
        }
        backtracking(nums, i + 1, num | nums[i]);
        backtracking(nums, i + 1, num);
    }
};

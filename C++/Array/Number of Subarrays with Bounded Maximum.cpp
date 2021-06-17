#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
 */

class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &nums, int min, int max) {
        int res = 0, left = 0, right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max) left = i;
            if (nums[i] >= min) right = i;
            res += right - left;
        }
        return res;
    }
};
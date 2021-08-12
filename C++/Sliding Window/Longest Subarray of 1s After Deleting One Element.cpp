#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 * */

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int res, count;
        res = count = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            count += nums[right] == 0;
            while (count > 1) count -= nums[left++] == 0;
            res = max(res, right - left);
        }
        return res;
    }
};
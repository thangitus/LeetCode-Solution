#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-increasing-subsequence/
 * */

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > sub.back())
                sub.push_back(nums[i]);
            else {
                int index = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                sub[index] = nums[i];
            }
        }
        return sub.size();
    }
};

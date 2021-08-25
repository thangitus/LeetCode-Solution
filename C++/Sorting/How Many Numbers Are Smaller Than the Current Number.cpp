#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 * */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> map;
        for (int i = sorted.size() - 1; i >= 0; i--)
            map[sorted[i]] = i;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
            ans[i] = map[nums[i]];
        return ans;
    }
};

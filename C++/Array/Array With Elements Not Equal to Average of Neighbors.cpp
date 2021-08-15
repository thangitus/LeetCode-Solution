#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
 * */

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j--]);
        }
        if (nums.size() % 2) ans.push_back(nums[i]);
        return ans;
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/3sum/
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) left++;
                else if (sum > 0) right--;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    int numLeft = nums[left];
                    while (left < right && numLeft == nums[left]) left++;
                }
            }
            while (i < n - 2 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};

#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> ans;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int numLeft = abs(nums[left]);
            int numRight = abs(nums[right]);
            if (numRight > numLeft) {
                ans.push_back(numRight * numRight);
                right--;
            } else {
                ans.push_back(numLeft * numLeft);
                left++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
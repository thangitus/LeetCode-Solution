#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * */

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right])
                return nums[left];
            int mid = (left + right) / 2;
            if (nums[mid] >= nums[left])
                left = mid + 1;
            else right = mid;
        }

        return nums[left];
    }
};

#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/single-element-in-a-sorted-array/
 * */

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2) mid--;
            if (nums[mid] != nums[mid + 1]) right = mid;
            else left = mid + 2; // Skip current element and next element
        }
        return nums[left];
    }
};
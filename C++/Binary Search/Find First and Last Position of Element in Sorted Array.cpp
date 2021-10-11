#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * */

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result(2, -1);
        if (nums.empty()) return result;
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = (right + left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] != target) return result;
        result[0] = left, right = n - 1;
        while (left < right) {
            int mid = (right + left) / 2 + 1;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        result[1] = right;
        return result;
    }
};

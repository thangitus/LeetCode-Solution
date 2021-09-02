#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/search-insert-position/
 * */

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) return mid;
            if (target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * */

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[right] || nums[mid] < nums[left]) { //right side is sorted or left side is unsorted
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else right = mid - 1;
            } else if (nums[mid] > nums[left] ||
                       nums[mid] > nums[right]) {  //left side is sorted or right side is unsorted
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else left = mid + 1;
            } else { left++, right--; }  //nums[start] == nums[mid] == nums[end]
        }
        return false;
    }
};



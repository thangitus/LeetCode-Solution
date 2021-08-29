#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-peak-element/
 * */

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid1 = (high - low) / 2 + low;
            int mid2 = mid1 + 1;
            if (nums[mid1] < nums[mid2]) low = mid2;
            else high = mid1;
        }
        return low;
    }
};

#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * */

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size(), start = -1, end = -2, minVal = nums[n - 1], maxVal = nums[0];
        for (int i = 1; i < n; i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[n - i - 1]);
            if (nums[i] < maxVal) end = i;
            if (nums[n - i - 1] > minVal) start = n - i - 1;
        }
        return end - start + 1;
    }
};

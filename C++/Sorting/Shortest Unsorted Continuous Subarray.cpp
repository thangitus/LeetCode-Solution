#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * */

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int size = nums.size(), left = 0, right = size - 1;
        while (left < size && nums[left] == sorted[left]) left++;
        while (right >= 0 && nums[right] == sorted[right]) right--;
        int result = right - left + 1;
        return result < 0 ? 0 : result;
    }
};

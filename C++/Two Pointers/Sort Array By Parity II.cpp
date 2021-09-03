#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/binary-subarrays-with-sum/
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        int n = nums.size();
        for (int even = 0, odd = 1; even < n; even += 2, odd += 2) {
            while (odd < n && nums[odd] & 1) odd += 2;
            while (even < n && !(nums[even] & 1)) even += 2;
            if (even < n) swap(nums[even], nums[odd]);
        }
        return nums;
    }
};

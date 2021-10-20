#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/subarray-product-less-than-k/
 * */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) return 0;
        int pro = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            pro *= nums[right];
            while (pro >= k) pro /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
};
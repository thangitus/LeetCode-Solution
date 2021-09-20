#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-product-subarray/
 * */

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int result, curMax, curMin;
        result = curMax = curMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i], maxTmp = curMax;
            curMax = max({num, curMin * num, curMax * num});
            curMin = min({num, curMin * num, maxTmp * num});
            result = max(curMax, result);
        }
        return result;
    }
};

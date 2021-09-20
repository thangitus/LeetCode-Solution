#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
 * */

class Solution {
public:
    int getMaxLen(vector<int> &nums) {
        int n = nums.size(), result;
        vector<int> pos(n), neg(n);
        result = pos[0] = nums[0] > 0, neg[0] = nums[0] < 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                pos[i] = pos[i - 1] + 1;
                neg[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                pos[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
                neg[i] = pos[i - 1] + 1;
            }
            result = max(result, pos[i]);
        }
        return result;
    }
};

#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sum-of-all-subset-xor-totals/
 * */

class Solution {
public:
    int subsetXORSum(vector<int> &nums) {
        int result = 0, n = nums.size(), numSubset = 1 << n;
        for (int bit = 1; bit < numSubset; bit++) {
            int cur = 0, mask = bit;
            for (int i = 0; i < n; i++) {
                if (mask & 1) cur ^= nums[i];
                mask >>= 1;
            }
            result += cur;
        }
        return result;
    }
};

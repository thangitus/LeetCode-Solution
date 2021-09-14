#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
 * */

class Solution {
public:
    int findBestValue(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        while (i < n && target > nums[i] * (n - i))
            target -= nums[i++];
        if (i == n) return nums.back();
        return ceil((double) target / (n - i) - 0.5);
    }
};

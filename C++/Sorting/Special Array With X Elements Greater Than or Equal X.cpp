#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
 * */

class Solution {
public:
    int specialArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        auto n = nums.size();
        for (int i = 1; i <= n; i++) {
            auto pos = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            auto remain = n - pos;
            if (remain == i) return i;
        }
        return -1;
    }
};

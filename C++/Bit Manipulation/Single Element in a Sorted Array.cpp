#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/single-element-in-a-sorted-array/
 * */

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int result = 0;
        for (int &val:nums) result ^= val;
        return result;
    }
};
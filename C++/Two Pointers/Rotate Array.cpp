#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/rotate-array/
 * */

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

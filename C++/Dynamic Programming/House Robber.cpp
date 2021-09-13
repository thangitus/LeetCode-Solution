#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/house-robber/
 * */

class Solution {
public:
    int rob(vector<int> &nums) {
        int pre = 0, cur = 0;
        for (int &val : nums) {
            int temp = max(pre + val, cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/concatenation-of-array/
 * */

class Solution {
public:
    vector<int> getConcatenation(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n * 2);
        for (int i = 0; i < n; i++)
            ans[i] = ans[i + n] = nums[i];
        return ans;
    }
};
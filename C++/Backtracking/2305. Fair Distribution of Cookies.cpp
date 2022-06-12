#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nums;
    int n;

    int distributeCookies(vector<int> &cookies, int k) {
        nums = cookies, n = k;
        vector<int> sum(k);
        return backtracking(sum, 0);
    }

    int backtracking(vector<int> &sum, int cur) {
        if (cur == nums.size())
            return *max_element(sum.begin(), sum.end());
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            sum[i] += nums[cur];
            res = min(res, backtracking(sum, cur + 1));
            sum[i] -= nums[cur];
        }
        return res;
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        unordered_map<int, int> dp; //LIS
        int res = 0;
        for (int &num: nums) {
            dp[num] = dp[num - diff] + 1;
            res += dp[num] >= 3;
        }
        return res;
    }
};

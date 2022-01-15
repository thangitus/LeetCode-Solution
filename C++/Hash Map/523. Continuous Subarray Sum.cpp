#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = sum % k;
            if (seen.count(mod)) return true;
            seen.insert(pre);
            pre = mod;
        }
        return false;
    }
};

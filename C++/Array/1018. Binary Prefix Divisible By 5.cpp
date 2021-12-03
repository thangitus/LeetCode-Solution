#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &nums) {
        vector<bool> result(nums.size());
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur = 2 * cur + nums[i];
            result[i] = cur % 5 == 0;
            cur = cur % (int) 1e9;
        }
        return result;
    }
};

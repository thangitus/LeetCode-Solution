#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangularSum(vector<int> &nums) {
        for (int j = 1; j < nums.size(); ++j)
            for (int i = 0; i < nums.size() - j; ++i) {
                nums[i] += nums[i + 1];
                nums[i] %= 10;
            }
        return nums[0];
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int> &nums) {
        long long result = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            result += max(nums[i] - nums[i - 1], 0);
        return result;
    }
};

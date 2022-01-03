#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        for (int i = nums.size() - 1; i - k + 1 >= 0; --i)
            result = min(result, nums[i] - nums[i - k + 1]);
        return result;
    }
};

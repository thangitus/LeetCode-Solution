#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int> &nums) {
        long long sum = 0, left = 0;
        for (int &num: nums) sum += num;
        int n = nums.size(), resId = 0, res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            left += nums[i];
            auto right = sum - left,
                    avgLeft = left / (i + 1),
                    avgRight = i < n - 1 ? right / (n - i - 1) : 0,
                    diff = abs(avgLeft - avgRight);
            if (diff < res) res = diff, resId = i;
        }
        return resId;
    }
};

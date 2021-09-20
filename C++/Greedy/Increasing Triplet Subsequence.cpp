#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/increasing-triplet-subsequence/
 * */

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int n = nums.size();
        vector<int> maxRight(n), minLeft(n);
        if (n < 3) return false;
        maxRight[n - 1] = nums[n - 1], minLeft[0] = nums[0];
        for (int i = 1; i < n; i++) minLeft[i] = min(minLeft[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i--) maxRight[i] = max(maxRight[i + 1], nums[i]);
        for (int j = 1; j < n - 1; j++)
            if (nums[j] > minLeft[j - 1] && nums[j] < maxRight[j + 1])
                return true;

        return false;
    }
};

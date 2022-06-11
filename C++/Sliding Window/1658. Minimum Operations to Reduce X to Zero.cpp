#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int maxLen = -1, left = 0, curSum = 0, n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0) - x;
        for (int right = 0; right < n; ++right) {
            curSum += nums[right];
            while (curSum > k && left <= right) curSum -= nums[left++];
            if (curSum == k) maxLen = max(maxLen, right - left + 1);
        }
        return maxLen != -1 ? n - maxLen : -1;
    }
};

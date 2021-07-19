#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/frequency-of-the-most-frequent-element/
 */

class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, res = 0;
        long long sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            long long expect = nums[right] * long(right - left + 1);
            while (expect - sum > k) {
                sum -= nums[left++];
                expect = nums[right] * long(right - left);
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

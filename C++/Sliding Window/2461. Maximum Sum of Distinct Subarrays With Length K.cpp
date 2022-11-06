#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        long long result = 0, curSum = 0, left = 0;
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            while (seen.count(nums[i]) || seen.size() >= k) {
                int num = nums[left++];
                seen.erase(num), curSum -= num;
            }
            seen.insert(nums[i]);
            curSum += nums[i];
            if (seen.size() == k) result = max(result, curSum);
        }
        return result;
    }
};

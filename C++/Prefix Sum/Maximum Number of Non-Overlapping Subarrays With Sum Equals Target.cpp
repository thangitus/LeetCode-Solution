#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
 */

class Solution {
public:
    int maxNonOverlapping(vector<int> &nums, int target) {
        unordered_set<int> seen;
        int curSum = 0, result = 0;
        seen.insert(curSum);
        for (int &num:nums) {
            curSum += num;
            if (seen.count(curSum - target)) {
                result++;
                seen.clear();
                curSum = 0;
                seen.insert(curSum);
            } else seen.insert(curSum);
        }
        return result;
    }
};

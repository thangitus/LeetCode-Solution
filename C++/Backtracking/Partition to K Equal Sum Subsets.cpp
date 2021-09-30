#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
 */

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        for (int num:nums)sum += num;
        if (k <= 0 || sum % k != 0)return false;
        vector<bool> visited(nums.size());
        return canPartition(nums, visited, 0, k, 0, 0, sum / k);
    }

    bool canPartition(vector<int> &nums, vector<bool> &visited, int start, int k, int curSum, int curNum, int target) {
        if (k == 1)return true;
        if (curSum == target && curNum > 0)
            return canPartition(nums, visited, 0, k - 1, 0, 0, target);
        for (int i = start; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (canPartition(nums, visited, i + 1, k, curSum + nums[i], curNum++, target))return true;
                visited[i] = false;
            }
        }
        return false;
    }
};

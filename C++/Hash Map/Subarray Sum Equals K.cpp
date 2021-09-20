#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/subarray-sum-equals-k/
 * */

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        int sum, result;
        sum = result = 0, map[0] = 1;
        for (int &num:nums) {
            sum += num;
            result += map[sum - k];
            map[sum]++;
        }
        return result;
    }
};

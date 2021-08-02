#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/two-sum/
 * */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(target - nums[i]) != map.end()) {
                ans.push_back(i);
                ans.push_back(map[target - nums[i]]);
                break;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};
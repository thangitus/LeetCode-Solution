#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/3sum-with-multiplicity/
 */

class Solution {
public:
    int threeSumMulti(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < nums.size(); i++) {
            res = (res + map[target - nums[i]]) % mod;
            for (int j = 0; j < i; j++)
                map[nums[i] + nums[j]]++;
        }
        return res;
    }
};
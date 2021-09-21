#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/contiguous-array/
 * */

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> map;
        int result = 0, sum = 0;
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            if (map.find(sum) != map.end())
                result = max(result, i - map[sum]);
            else map[sum] = i;
        }
        return result;
    }
};

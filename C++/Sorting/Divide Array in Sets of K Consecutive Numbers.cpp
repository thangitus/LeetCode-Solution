#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * */

class Solution {
public:
    bool isPossibleDivide(vector<int> &nums, int k) {
        if (nums.size() % k) return false;
        unordered_map<int, int> map;
        for (int &num:nums) map[num]++;
        sort(nums.begin(), nums.end());
        for (int &num:nums)
            if (map[num]) {
                for (int i = num; i < num + k; i++)
                    if (map[i]) map[i]--;
                    else return false;
            }
        return true;
    }
};


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] == nums[i + 1]) nums[i] *= 2, nums[i + 1] = 0;
        for (int i = 0, left = 0; i < nums.size(); ++i)
            if (nums[i]) swap(nums[i], nums[left++]);

        return nums;
    }
};
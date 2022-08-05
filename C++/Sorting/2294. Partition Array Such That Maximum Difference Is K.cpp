#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1, left = 0;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] - nums[left] > k)
                res++, left = i;

        return res;
    }
};

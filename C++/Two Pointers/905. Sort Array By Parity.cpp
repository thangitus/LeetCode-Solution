#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int right = nums.size() - 1;
        for (int i = right; i >= 0; --i)
            if (nums[i] & 1)
                swap(nums[i], nums[right--]);

        return nums;
    }
};

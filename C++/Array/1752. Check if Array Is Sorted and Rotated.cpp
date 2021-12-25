#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int> &nums) {
        int pos = -1, count = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] > nums[i + 1]) {
                pos = i;
                count++;
            }
        if (pos == -1) return true;
        if (count != 1) return false;
        return nums[pos] >= nums.back() && nums.back() <= nums[0];
    }
};

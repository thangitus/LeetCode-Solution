#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/non-decreasing-array/
 */

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int modified = 0, prev = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < prev) {
                if (++modified > 1) return false;
                if (i - 2 >= 0 && nums[i - 2] > nums[i]) continue;
            }
            prev = nums[i];
        }
        return true;
    }
};
#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/sort-colors/
 */

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                left++;
            else if (nums[i] == 2)
                right--;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < left)nums[i] = 0;
            else if (i > right)nums[i] = 2;
            else nums[i] = 1;
        }
    }
};
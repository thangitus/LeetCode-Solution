#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (int &num:nums) {
            if (nums[abs(num) - 1] < 0)
                result.push_back(abs(num));
            else nums[abs(num) - 1] *= -1;
        }
        return result;
    }
};

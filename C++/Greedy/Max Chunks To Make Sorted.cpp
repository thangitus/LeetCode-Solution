#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/max-chunks-to-make-sorted/
 * */

class Solution {
public:
    int maxChunksToSorted(vector<int> &nums) {
        int result = 0, maxVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
            if (maxVal == i) result++;
        }
        return result;
    }
};

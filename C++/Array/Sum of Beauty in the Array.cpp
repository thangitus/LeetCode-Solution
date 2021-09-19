#include <bits/stdc++.h>

using namespace std;
/**
 * https://leetcode.com/problems/sum-of-beauty-in-the-array/
 * */

class Solution {
public:
    int sumOfBeauties(vector<int> &nums) {
        int n = nums.size(), result = 0;
        vector<int> maxNums(n), minNums(n);
        maxNums[0] = nums[0], minNums[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            maxNums[i] = max(maxNums[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i--)
            minNums[i] = min(minNums[i + 1], nums[i]);
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > maxNums[i - 1] && nums[i] < minNums[i + 1])
                result += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                result += 1;
        }
        return result;
    }
};
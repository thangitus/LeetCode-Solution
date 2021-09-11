#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
 * */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int result = 0;
        vector<unordered_map<int, int>> maps(nums.size());
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < i; j++) {
                if (abs((long) nums[i] - nums[j]) > INT_MAX) continue;
                int diff = nums[i] - nums[j];
                int count = maps[j][diff];
                maps[i][diff] = maps[i][diff] + count + 1;
                result += count;
            }
        return result;
    }
};

int main() {
    vector<int> nums{2, 4, 6, 8, 10};
    Solution solution;
    solution.numberOfArithmeticSlices(nums);
}
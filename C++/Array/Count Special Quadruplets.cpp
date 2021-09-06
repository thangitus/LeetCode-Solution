#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-special-quadruplets/
 */

class Solution {
public:
    int countQuadruplets(vector<int> &nums) {
        const auto n = nums.size();
        unordered_map<int, int> count;
        count[nums.back()] = 1;
        int result = 0;
        for (int i = n - 2; i > 1; --i) {
            for (int j = i - 1; j > 0; --j)
                for (int k = j - 1; k >= 0; --k)
                    result += count[nums[i] + nums[j] + nums[k]];

            count[nums[i]] += 1;
        }
        return result;
    }
};
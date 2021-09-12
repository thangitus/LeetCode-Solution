#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/permutations/
 * Refs: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> permute(vector<int> &nums) {
        permuteRecursive(nums, 0);
        return result;
    }

    void permuteRecursive(vector<int> &num, int begin) {
        if (begin >= num.size()) {
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1);
            swap(num[begin], num[i]);
        }
    }
};

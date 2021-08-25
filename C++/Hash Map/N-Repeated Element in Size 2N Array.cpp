#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
 * */

class Solution {
public:
    int repeatedNTimes(vector<int> &nums) {
        unordered_set<int> seen;
        for (int &num:nums) {
            if (seen.count(num)) return num;
            seen.insert(num);
        }
        return -1;
    }
};
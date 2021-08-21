#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sum-of-unique-elements/
 * */

class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int x:nums)map[x]++;
        int sum = 0;
        for (const auto &item : map)
            if (item.second == 1) sum += item.first;
        return sum;
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-lucky-integer-in-an-array/
 * */

class Solution {
public:
    int findLucky(vector<int> &arr) {
        unordered_map<int, int> map;
        for (int &num:arr) map[num]++;
        int ans = -1;
        for (auto &item:map)
            if (item.first == item.second && item.second > ans)
                ans = item.second;
            return ans;
    }
};

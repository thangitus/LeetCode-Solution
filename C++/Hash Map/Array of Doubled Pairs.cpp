#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-consecutive-sequence/
 * */

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> map;
        for (int i:arr) {
            if (i >= 0 && i % 2 == 0 && map[i / 2])map[i / 2]--;
            else if (i < 0 && map[i * 2])map[i * 2]--;
            else map[i]++;
        }
        for (const auto &item : map)
            if (item.second) return false;
        return true;
    }
};

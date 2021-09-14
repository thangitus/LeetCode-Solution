#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
 * */

class Solution {
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr) {
        unordered_map<int, int> count;
        for (int i = 0; i < target.size(); i++) {
            count[target[i]]++;
            count[arr[i]]--;
        }
        for (auto &item:count)
            if (item.second) return false;
        return true;
    }
};

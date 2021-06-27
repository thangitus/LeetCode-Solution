#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/unique-number-of-occurrences/
 * */

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> map;
        for (auto &i:arr) map[i]++;
        unordered_set<int> set;
        for (auto &item:map) {
            if (set.find(item.second) != set.end()) return false;
            set.insert(item.second);
        }
        return true;
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-original-array-from-doubled-array/
 * */

class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        int n = changed.size();
        if (n % 2) return {};
        vector<int> result;
        unordered_map<int, int> map;
        for (int &num:changed)map[num]++;
        sort(changed.begin(), changed.end());
        for (int &num:changed) {
            if (map[num] && map[num * 2]) {
                result.push_back(num);
                map[num]--;
                map[num * 2]--;
            }
        }
        for (auto &item:map)
            if (item.second) return {};
        return result;
    }
};
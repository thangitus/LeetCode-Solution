#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/rank-transform-of-an-array/
 * */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        vector<int> sorted = arr, ans;
        unordered_map<int, int> map;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < sorted.size(); i++)
            if (!map[sorted[i]]) map[sorted[i]] = map.size() + 1;
        for (int &num:arr) ans.push_back(map[num]);
        return ans;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int> &nums) {
        unordered_map<int, int> count;
        vector<int> res(2);
        for (int num: nums) count[num]++;
        for (auto &item: count)
            res[0] += item.second / 2, res[1] += item.second % 2;
        return res;
    }
};
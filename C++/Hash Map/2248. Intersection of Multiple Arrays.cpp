#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>> &nums) {
        unordered_map<int, int> count;
        for (auto &i: nums)
            for (int &num: i) count[num]++;
        vector<int> result;
        for (auto &item: count)
            if (item.second == nums.size())
                result.push_back(item.first);
        sort(result.begin(), result.end());
        return result;
    }
};

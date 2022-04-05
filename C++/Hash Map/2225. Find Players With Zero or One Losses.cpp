#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        unordered_map<int, int> map;
        vector<vector<int>> result(2);
        for (auto &match: matches) {
            if (map.find(match[0]) == map.end())
                map[match[0]] = 0;
            map[match[1]]++;
        }
        for (auto &item: map)
            if (item.second == 0)
                result[0].push_back(item.first);
            else if (item.second == 1)
                result[1].push_back(item.first);
        for (auto &item: result)
            sort(item.begin(), item.end());
        return result;
    }
};

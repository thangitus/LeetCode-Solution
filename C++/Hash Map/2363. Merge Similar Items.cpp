#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2) {
        map<int, int> count;
        for (auto &item: items1) count[item[0]] += item[1];
        for (auto &item: items2) count[item[0]] += item[1];
        vector<vector<int>> res;
        for (auto &item: count)
            res.push_back({item.first, item.second});
        return res;
    }
};
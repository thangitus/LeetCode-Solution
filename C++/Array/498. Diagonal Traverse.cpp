#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        map<int, vector<int>> map;
        vector<int> result;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                map[i + j].push_back(mat[i][j]);
        for (auto &item: map) {
            if (item.first % 2)
                reverse(item.second.begin(), item.second.end());
            result.insert(result.begin(), item.second.begin(), item.second.end());
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

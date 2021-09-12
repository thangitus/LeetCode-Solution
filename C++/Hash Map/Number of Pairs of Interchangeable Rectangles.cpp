#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        unordered_map<double, int> maps;
        long long result = 0;
        for (auto &rectangle:rectangles) {
            double div = (double) rectangle[0] / rectangle[1];
            result += maps[div];
            maps[div]++;
        }
        return result;
    }
};
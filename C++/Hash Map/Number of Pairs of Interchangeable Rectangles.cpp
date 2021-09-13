#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
 * */

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        unordered_map<double, int> maps;
        long long result = 0;
        for (auto &rectangle:rectangles)
            result += maps[(double) rectangle[0] / rectangle[1]]++;
        return result;
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/range-addition-ii/
 */

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        if (ops.empty())return m * n;
        int minX = INT_MAX, minY = INT_MAX;
        for (auto &op:ops) {
            minX = min(minX, op[0]);
            minY = min(minY, op[1]);
        }
        return minX * minY;
    }
};
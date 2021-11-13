#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/daily-temperatures/
 * */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> pos(101, -1), result(temperatures.size(), INT_MAX);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            for (int c = temperatures[i] + 1; c <= 100; c++)
                if (pos[c] != -1)
                    result[i] = min(pos[c] - i, result[i]);
            pos[temperatures[i]] = i;
            if (result[i] == INT_MAX) result[i] = 0;
        }
        return result;
    }
};

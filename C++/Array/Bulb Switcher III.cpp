#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/bulb-switcher-iii/
 * */

class Solution {
public:
    int numTimesAllBlue(vector<int> &light) {
        int right = 0, result = 0;
        for (int i = 1; i <= light.size(); i++) {
            right = max(right, light[i - 1]);
            result += right == i;
        }
        return result;
    }
};
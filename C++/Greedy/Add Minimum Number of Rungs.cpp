#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/add-minimum-number-of-rungs/
 * */

class Solution {
public:
    int addRungs(vector<int> &rungs, int dist) {
        int result = 0, current = 0;
        for (int &rung:rungs) {
            result += (rung - current - 1) / dist;
            current = rung;
        }
        return result;
    }
};

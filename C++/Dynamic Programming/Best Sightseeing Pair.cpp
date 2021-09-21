#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/best-sightseeing-pair/
 * */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int result = 0, cur = 0;
        for (int &num:values) {
            result = max(result, cur + num);
            cur = max(cur, num) - 1;
        }
        return result;
    }
};

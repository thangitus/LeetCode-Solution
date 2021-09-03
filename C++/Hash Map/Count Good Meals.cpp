#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-good-meals/
 * */

class Solution {
public:
    int countPairs(vector<int> &deliciousness) {
        unordered_map<int, int> map;
        int mod = 1000000007, result = 0;
        for (int &num:deliciousness) {
            int power = 1;
            for (int i = 0; i < 22; i++) {
                result += map[power - num];
                result %= mod;
                power <<= 1;
            }
            map[num]++;
        }
        return result;
    }
};
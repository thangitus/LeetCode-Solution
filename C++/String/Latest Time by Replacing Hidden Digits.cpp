#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/
 * */

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') time[0] = time[1] < '4' || time[1] == '?' ? '2' : '1';
        if (time[1] == '?') time[1] = time[0] == '2' ? '3' : '9';
        if (time[3] == '?') time[1] = '5';
        if (time[4] == '?') time[4] = '9';
        return time;
    }
};
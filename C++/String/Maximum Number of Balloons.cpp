#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-number-of-balloons/
 * */

class Solution {
public:
    string balloon = "balloon";
    int maxNumberOfBalloons(string text) {
        vector<int> count(26);
        for (char &ch:text) count[ch - 'a']++;
        count['l' - 'a'] /= 2, count['o' - 'a'] /= 2;
        int result = INT_MAX;
        for (char &ch:balloon) result = min(count[ch - 'a'], result);
        return result;
    }
};

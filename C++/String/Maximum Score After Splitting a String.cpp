#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-score-after-splitting-a-string/
 * */

class Solution {
public:
    int maxScore(string s) {
        int count[]{0, 0}, result = INT_MIN;
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - '0']++;
            if (i != s.length() - 1)
                result = max(count[0] - count[1], result);
        }
        return result + count[1];
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
 * */

class Solution {
public:
    int minTimeToType(string word) {
        int res = 0;
        char cur = 'a';
        for (char &ch:word) {
            int distance = min(abs(cur - ch), 26 - abs(cur - ch));
            res += distance + 1;
            cur = ch;
        }
        return res;
    }
};

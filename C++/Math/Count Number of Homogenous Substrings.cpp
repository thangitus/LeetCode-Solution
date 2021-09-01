#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-number-of-homogenous-substrings/
 * */

class Solution {
public:
    int countHomogenous(string s) {
        int result = 0, count = 0, mod = 1e9 + 7;
        char cur = 0;
        for (char &ch:s) {
            count = cur == ch ? count + 1 : 1;
            cur = ch;
            result = (result + count) % mod;
        }
        return result;
    }
};

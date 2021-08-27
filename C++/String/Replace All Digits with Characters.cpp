#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/replace-all-digits-with-characters/
 * */

class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.length(); i += 2)
            s[i] = s[i] - '0' + s[i - 1];
        return s;
    }
};
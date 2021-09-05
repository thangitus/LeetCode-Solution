#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/orderly-queue/
 * */

class Solution {
public:
    string orderlyQueue(string str, int K) {
        if (K > 1) {
            sort(str.begin(), str.end());
            return str;
        }
        string res = str;
        for (int i = 1; i < str.length(); i++)
            res = min(res, str.substr(i) + str.substr(0, i));
        return res;
    }
};

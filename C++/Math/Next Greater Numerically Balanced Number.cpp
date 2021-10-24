#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/next-greater-numerically-balanced-number/
 */

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int result = n + 1;
        while (!isValid(result))
            result++;
        return result;
    }

    bool isValid(int num) {
        string s = to_string(num);
        vector<int> count(10, 0);
        for (char c:s)
            count[c - '0']++;
        for (char c:s)
            if (count[c - '0'] != c - '0')
                return false;
        return true;
    }
};

#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/break-a-palindrome/
 * */

class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.length();
        if (n == 1) return "";
        for (int i = 0; i < n; i++) {
            if (s[i] != 'a' && !isMiddle(n, i)) {
                s[i] = 'a';
                return s;
            }
        }
        s.back() = 'b';
        return s;
    }

    bool isMiddle(int &n, int &i) {
        return n % 2 && n / 2 == i;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2) return false;
        int free, open, close;
        free = open = close = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '0') free++;
            else if (s[i] == '(') open++;
            else close++;
            if (free + open - close < 0) return false;
        }
        free = open = close = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (locked[i] == '0') free++;
            else if (s[i] == '(') open++;
            else close++;
            if (free + close - open < 0) return false;
        }
        return true;
    }
};


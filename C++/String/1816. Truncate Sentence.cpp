#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ')k--;
            if (k == 0) return s.substr(0, i);
            i++;
        }
        return s;
    }
};

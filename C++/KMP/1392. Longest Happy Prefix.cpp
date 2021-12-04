#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int len = s.length();
        vector<int> prefix(len);
        for (int i = 1, j = 0; s[i]; i++) {
            while (j && s[i] != s[j]) j = prefix[j - 1];
            if (s[i] == s[j])j++;
            prefix[i] = j;
        }
        return s.substr(0,prefix.back());
    }
};
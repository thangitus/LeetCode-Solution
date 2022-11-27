#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int cur = 0;
        for (char &c: s) {
            if (t[cur] == c) cur++;
            if (cur == t.length()) return 0;
        }
        return t.length() - cur;
    }
};

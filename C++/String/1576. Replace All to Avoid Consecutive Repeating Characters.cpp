#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for (auto i = 0; i < s.size(); ++i)
            if (s[i] == '?')
                for (s[i] = 'a'; s[i] <= 'c'; ++s[i])
                    if ((i == 0 || s[i - 1] != s[i]) && (i == s.size() - 1 || s[i + 1] != s[i]))
                        break;
        return s;
    }
};

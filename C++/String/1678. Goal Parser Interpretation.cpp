#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string interpret(string s) {
        string result;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == 'G') result += s[i];
            if (s[i] == '(') {
                if (s[i + 1] == ')') result += 'o', i += 1;
                else result += "al", i += 3;
            }
            i++;
        }
        return result;
    }
};

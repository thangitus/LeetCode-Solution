#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) {
        string result;
        for (int i = 0, cur = 0; i < s.length(); ++i) {
            if (cur < spaces.size() && i == spaces[cur]) {
                result += ' ';
                cur++;
            }
            result += s[i];
        }
        return result;
    }
};

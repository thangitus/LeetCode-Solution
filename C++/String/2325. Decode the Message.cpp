#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        int cur = 0;
        vector<int> pos(26, -1);
        for (char &c: key)
            if (c != ' ' && pos[c - 'a'] < 0)
                pos[c - 'a'] = cur++;

        for (char &c: message)
            if (c != ' ')
                c = 'a' + pos[c - 'a'];
        return message;
    }
};

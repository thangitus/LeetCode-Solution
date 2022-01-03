#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        string result;
        vector<int> count(26);
        for (char c: s) ++count[c - 'a'];
        while (result.size() < s.size()) {
            for (int i = 0; i < 26; ++i)
                if (--count[i] >= 0)
                    result += char(i + 'a');
            for (int i = 25; i >= 0; --i)
                if (--count[i] >= 0)
                    result += char(i + 'a');
        }
        return result;
    }
};

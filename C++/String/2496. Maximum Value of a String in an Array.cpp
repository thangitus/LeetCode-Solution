#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumValue(vector<string> &strs) {
        int res = 0;
        for (auto &s: strs) {
            int count = 0;
            for (char &c: s) count += ::isdigit(c);
            res = max(res, int(count == s.length() ? stoi(s) : s.length()));
        }
        return res;
    }
};

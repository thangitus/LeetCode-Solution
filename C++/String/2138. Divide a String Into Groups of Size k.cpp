#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int i = 0;
        while (i < s.length()) {
            result.push_back(s.substr(i, k));
            i += k;
        }
        string back = result.back();
        while (back.length() < k)
            back += fill;
        result.back() = back;
        return result;
    }
};
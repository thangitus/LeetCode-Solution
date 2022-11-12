#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string cur;
        for (char &c: s) {
            cur += c;
            while (cur.size() >= 3 && cur.substr(cur.size() - 3) == "abc")
                cur.pop_back(), cur.pop_back(), cur.pop_back();
        }
        while (cur.size() >= 3 && cur.substr(cur.size() - 3) == "abc")
            cur.pop_back(), cur.pop_back(), cur.pop_back();
        return cur.empty();
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string res;
        for (char &c: s) {
            res += c;
            int n = res.size();
            while (res.size() >= 2 && tolower(res[n - 1]) == tolower(res[n - 2]) && res[n - 1] != res[n - 2])
                res.pop_back(), res.pop_back(), n = res.size();
        }
        return res;
    }
};

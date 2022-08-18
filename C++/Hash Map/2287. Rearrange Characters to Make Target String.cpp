#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> countS, countTarget;
        for (char &c: s) countS[c]++;
        for (char &c: target) countTarget[c]++;
        int res = INT_MAX;
        for (auto &item: countTarget)
            res = min(res, countS[item.first] / item.second);
        return res;
    }
};
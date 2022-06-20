#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        unordered_set<string> set(words.begin(), words.end());
        for (string &w: words)
            for (int i = 0; i < w.length(); ++i)
                set.erase(w.substr(i));
        int res = 0;
        for (auto &item: set)
            res += item.length() + 1;
        return res;
    }
};

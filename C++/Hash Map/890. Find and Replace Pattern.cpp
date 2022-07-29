#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        string p = value(pattern);
        vector<string> res;
        for (string &word: words)
            if (value(word) == p) res.push_back(word);
        return res;
    }

    string value(string &word) {
        unordered_map<char, unsigned int> map;
        for (char &c: word)
            if (map.find(c) == map.end())
                map[c] = map.size();
        string s;
        for (char &c: word) s += char('a' + map[c]);
        return s;
    }
};
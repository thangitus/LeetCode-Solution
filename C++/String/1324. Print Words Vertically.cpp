#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        int maxLen = 0;
        while (ss >> word) {
            words.push_back(word);
            maxLen = max(maxLen, (int) word.length());
        }
        vector<string> result(maxLen, string(words.size(), ' '));
        for (int c = 0; c < words.size(); ++c)
            for (int r = 0; r < words[c].length(); ++r)
                result[r][c] = words[c][r];
        for (auto &item: result)
            while (item.back() == ' ')
                item.pop_back();
        return result;
    }
};

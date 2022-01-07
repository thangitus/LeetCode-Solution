#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1);
        string word;
        unordered_map<string, int> count;
        while (ss >> word) count[word]++;
        ss = stringstream(s2);
        while (ss >> word) count[word]++;
        vector<string> result;
        for (auto &item: count)
            if (item.second == 1)
                result.push_back(item.first);
        return result;
    }
};

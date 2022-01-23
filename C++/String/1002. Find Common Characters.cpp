#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &words) {
        vector<string> result;
        vector<int> count(26, INT_MAX);
        for (string &word: words) {
            vector<int> countTmp(26);
            for (char &c: word)
                countTmp[c - 'a']++;
            for (int i = 0; i < 26; ++i)
                count[i] = min(countTmp[i], count[i]);
        }
        for (int i = 0; i < 26; i++)
            while (count[i]--)
                result.emplace_back(1, i + 'a');
        return result;
    }
};

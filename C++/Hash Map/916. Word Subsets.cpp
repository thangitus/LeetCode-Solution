#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        vector<int> count(26);
        for (string &word: words2) {
            auto tmp = counter(word);
            for (int i = 0; i < 26; i++)
                count[i] = max(count[i], tmp[i]);
        }
        vector<string> result;
        for (string &word: words1) {
            auto tmp = counter(word);
            int i = 0;
            for (; i < 26 && tmp[i] >= count[i]; i++);
            if (i == 26) result.push_back(word);
        }
        return result;
    }

private:
    vector<int> counter(string &word) {
        vector<int> count(26);
        for (char c: word) count[c - 'a']++;
        return count;
    }
};

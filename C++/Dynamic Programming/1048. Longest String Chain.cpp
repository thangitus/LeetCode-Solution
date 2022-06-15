#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool compare(string &w1, string &w2) {
        return w1.length() < w2.length();
    }

public:
    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for (auto &word: words) {
            for (int i = 0; i < word.length(); ++i) {
                auto s = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp.find(s) != dp.end() ? dp[s] + 1 : 1);
            }
            res = max(res, dp[word]);
        }
        return res;
    }
};

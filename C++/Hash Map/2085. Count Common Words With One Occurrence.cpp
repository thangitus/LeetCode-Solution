#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWords(vector<string> &words1, vector<string> &words2) {
        unordered_map<string, int> count;
        for (string &word: words1) count[word]++;
        for (string &word: words2)
            if (count[word] < 2) count[word]--;
        return count_if(begin(count), end(count),
                        [](const auto &p) { return p.second == 0; });
    }
};

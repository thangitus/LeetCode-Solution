#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords) {
        unordered_set<string> seen;
        for (string &word: startWords) {
            sort(word.begin(), word.end());
            seen.insert(word);
        }
        int result = 0;
        for (string &word: targetWords) {
            for (int i = 0; i < word.length(); ++i) {
                string start = word.substr(0, i) + word.substr(i + 1);
                sort(start.begin(), start.end());
                if (seen.count(start)) {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};


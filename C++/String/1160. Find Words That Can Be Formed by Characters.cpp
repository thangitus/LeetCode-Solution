#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string> &words, string chars) {
        vector<int> count(26);
        for (char c: chars) count[c - 'a']++;
        int result = 0;
        for (auto &word: words) {
            vector<int> countWord(26);
            int check = true;
            for (char c: word)
                if (++countWord[c - 'a'] > count[c - 'a']) {
                    check = false;
                    break;
                }
            if (check) result += word.length();
        }
        return result;
    }
};

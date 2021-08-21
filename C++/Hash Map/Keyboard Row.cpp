#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/keyboard-row/
 * */

class Solution {
public:
    vector<string> rows{"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    vector<string> findWords(vector<string> &words) {
        vector<int> map(255);
        for (int i = 0; i < 3; i++)
            for (char ch:rows[i]) map[ch] = i;
        vector<string> ans;
        for (auto word:words) {
            bool isValid = true;
            for (int i = 1; i < word.length() && isValid; i++)
                isValid = map[tolower(word[i])] == map[tolower(word[0])];
            if (isValid) ans.push_back(word);
        }
        return ans;
    }
};

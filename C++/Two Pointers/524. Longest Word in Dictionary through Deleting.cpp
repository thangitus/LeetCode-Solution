#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string> &dictionary) {
        string result;
        for (string &word: dictionary)
            if (isValid(s, word) && word.length() >= result.length()) {
                if (word.length() > result.length()) result = word;
                else result = min(result, word);
            }
        return result;
    }

    static bool isValid(string &s, string &t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) j++;
            i++;
        }
        return i <= s.length() && j == t.length();
    }
};

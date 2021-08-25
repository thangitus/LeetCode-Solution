#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-the-number-of-consistent-strings/
 * */

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string> &words) {
        bool alpha[26] = {};
        for (char &ch:allowed) alpha[ch - 'a'] = true;
        int count = words.size();
        for (auto &word:words) {
            for (char &ch:word)
                if (!alpha[ch - 'a']) {
                    count--;
                    break;
                }
        }
        return count;
    }
};

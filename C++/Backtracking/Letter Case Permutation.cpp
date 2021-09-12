#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/letter-case-permutation/
*/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        letterCasePermutation(s, result, 0);
        return result;
    }

    void letterCasePermutation(string &s, vector<string> &result, int i) {
        if (i == s.size()) {
            result.push_back(s);
            return;
        }
        if (isdigit(s[i])) letterCasePermutation(s, result, i + 1);
        else {
            s[i] = tolower(s[i]);
            letterCasePermutation(s, result, i + 1);
            s[i] = toupper(s[i]);
            letterCasePermutation(s, result, i + 1);

        }
    }
};

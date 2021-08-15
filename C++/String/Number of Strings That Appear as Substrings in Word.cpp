#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
 * */

class Solution {
public:
    int numOfStrings(vector<string> &patterns, string word) {
        int count = 0;
        for (auto &s:patterns)
            if (word.find(s) != string::npos) count++;
        return count;
    }
};

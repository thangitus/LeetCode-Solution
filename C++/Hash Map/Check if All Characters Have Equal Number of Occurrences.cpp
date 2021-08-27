#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
 * */

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> counts(26);
        int value;
        for (char &ch:s)value = ++counts[ch - 'a'];
        for (int &count:counts)
            if (count && count != value) return false;
        return true;
    }
};
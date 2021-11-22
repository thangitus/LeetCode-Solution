#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
 * */

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> count(26);
        for (char c: word1)count[c - 'a']++;
        for (char c: word2)count[c - 'a']--;
        for (int i: count)
            if (abs(i) > 3) return false;
        return true;
    }
};

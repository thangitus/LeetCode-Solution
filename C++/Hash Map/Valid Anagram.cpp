#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/valid-anagram/
 * */

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26);
        for (char &ch:s) count[ch - 'a']++;
        for (char &ch:t) count[ch - 'a']--;
        for (int &num:count)
            if (num) return false;
        return true;
    }
};
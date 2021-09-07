#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/first-unique-character-in-a-string/
 * */

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26);
        for (char &ch:s) count[ch - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (count[s[i] - 'a'] == 1) return i;
        return -1;
    }
};

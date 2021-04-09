#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/verifying-an-alien-dictionary/
 */

class Solution {
public:
    unordered_map<char, int> map;
    bool isAlienSorted(vector<string> &words, string order) {
        for (int i = 0; i < order.length(); i++)
            map[order[i]] = i;
        for (int i = 0; i < words.size() - 1; i++)
            if (!isSmaller(words[i], words[i + 1]))
                return false;
        return true;
    }

    bool isSmaller(string &s1, string &s2) {
        for (int i = 0; i < min(s1.length(), s2.length()); i++)
            if (map[s1[i]] < map[s2[i]]) return true;
            else if (map[s1[i]] > map[s2[i]]) return false;
        if (s1.length() <= s2.length()) return true;
        return false;
    }
};

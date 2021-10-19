#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> goal(26), cur(26), result;
        for (char &c : p) goal[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            cur[s[i] - 'a']++;
            if (i >= p.size()) cur[s[i - p.size()] - 'a']--;
            if (cur == goal) result.push_back(i - p.size() + 1);
        }
        return result;
    }
};
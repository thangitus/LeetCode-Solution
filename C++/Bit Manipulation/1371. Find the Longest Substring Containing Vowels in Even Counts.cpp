#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res = 0, mask = 0;
        unordered_map<int, int> pos{{0, -1}};
        string vowel = "aeiou";
        pos[0] = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (vowel.find(s[i]) != string::npos)
                mask ^= (1 << (s[i] - 'a'));
            if (!pos.count(mask)) pos[mask] = i;
            res = max(res, i - pos[mask]);
        }
        return res;
    }
};

#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/permutation-in-string/
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(128);
        for (char &ch:s1) count[ch]--;
        for (int l = 0, r = 0; r < s2.length(); r++) {
            count[s2[r]]++;
            if (count[s2[r]] > 0)
                while (--count[s2[l++]] != 0);
            else if ((r - l + 1) == s1.length()) return true;
        }
        return s1.length() == 0;
    }
};

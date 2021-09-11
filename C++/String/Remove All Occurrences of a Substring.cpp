#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
 * */

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = s;
        unsigned int m = part.length(), j = 0;
        for (int i = 0; i < s.length(); i++) {
            result[j++] = s[i];
            if (j >= m && result.substr(j - m, m) == part) j -= m;
        }
        return result.substr(0, j);
    }
};

#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/di-string-match/
 */

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length(), left = 0, right = n;
        vector<int> result;
        for (char &ch:s) {
            if (ch == 'I') result.push_back(left++);
            else result.push_back(right--);
        }
        result.push_back(left);
        return result;
    }
};

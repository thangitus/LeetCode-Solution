#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/remove-duplicate-letters/
 * */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        vector<int> last(128), used(128);
        for (int i = 0; i < s.length(); i++) last[s[i]] = i;
        for (int i = 0; i < s.length(); i++) {
            if (used[s[i]]) continue;
            while (!result.empty() && result.back() > s[i] && last[result.back()] > i) {
                used[result.back()] = 0;
                result.pop_back();
            }
            used[s[i]] = 1;
            result.push_back(s[i]);
        }
        return result;
    }
};

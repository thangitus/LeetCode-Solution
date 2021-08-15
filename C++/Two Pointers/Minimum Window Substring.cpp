#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-window-substring/
 * */

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> countT(255);
        for (char &ch:t)countT[ch]++;
        int ansLeft, length = INT_MAX;
        for (int right = 0, left = 0, count = 0; right < s.length(); right++) {
            if (countT[s[right]] > 0) count++;
            countT[s[right]]--;
            if (count == t.length()) {
                while (left < right && countT[s[left]] < 0) countT[s[left++]]++;
                if (length > right - left + 1) {
                    ansLeft = left;
                    length = right - left + 1;
                }
                countT[s[left++]]++;
                count--;
            }
        }
        return length == INT_MAX ? "" : s.substr(ansLeft, length);
    }
};

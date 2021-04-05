#include <bits/stdc++.h>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-window-substring/
 * */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countS, countT;
        for (char &ch:t)
            countT[ch]++;

        int left, ansLeft, right, ansRight, length = INT_MAX;
        left = right = 0;
        for (; right < s.length(); right++) {
            countS[s[right]]++;

            while (check(countS, countT)) {
                if (right - left + 1 < length) {
                    ansLeft = left;
                    ansRight = right;
                    length = right - left + 1;
                }
                countS[s[left++]]--;
            }
        }
        return length == INT_MAX ? "" : s.substr(ansLeft, ansRight - ansLeft + 1);
    }

    bool check(unordered_map<char, int> &countS, unordered_map<char, int> &countT) {
        for (auto &it : countT)
            if (it.second > countS[it.first])
                return false;
        return true;
    }
};
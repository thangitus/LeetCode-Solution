#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        int cnt[128] = {};
        for (auto ch: s) cnt[ch]++;
        for (auto ch = 'Z'; ch >= 'A'; --ch)
            if (cnt[ch] && cnt[ch + 'a' - 'A'])
                return {1, ch};
        return "";
    }
};
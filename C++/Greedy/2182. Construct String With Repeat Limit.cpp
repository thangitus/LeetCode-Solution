#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> counts(26);
        for (char &c: s)
            counts[c - 'a']++;
        string res;
        while (true) {
            int prevLen = res.length();
            bool hasNext = false;
            for (int i = 25; i >= 0; --i) {
                char c = char('a' + i);
                if (c == res.back()) continue;
                int count = 0;
                if (hasNext) {
                    if (counts[i]) {
                        res += c, counts[i]--;
                        break;
                    } else continue;
                }
                while (count < repeatLimit && counts[i]) {
                    res += c;
                    count++;
                    counts[i]--;
                }
                if (counts[i]) hasNext = true;
            }
            if (prevLen == res.length()) break;
        }
        return res;
    }
};
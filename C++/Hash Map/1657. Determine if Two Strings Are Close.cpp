#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> w1(26), w2(26);
        set<char> s1, s2;
        for (char c: word1)
            w1[c - 'a']++, s1.insert(c);
        for (char c: word2)
            w2[c - 'a']++, s2.insert(c);
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        return w1 == w2 && s1 == s2;
    }
};

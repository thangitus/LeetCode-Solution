#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26);
        for (char &c: s) count[c - 'a']++;
        int res = 0;
        unordered_set<int> seen;
        for (int i = 0; i < 26; ++i) {
            while (count[i] && seen.count(count[i]))
                count[i]--, res++;
            seen.insert(count[i]);
        }
        return res;
    }
};

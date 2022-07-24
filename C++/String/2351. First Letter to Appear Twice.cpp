#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> count(128);
        for (char c: s) {
            count[c]++;
            if (count[c] > 1) return c;
        }
        return ' ';
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int repeat = 0, result = 0;
        vector<int> map(128);
        for (int i = 0; s[i]; i++) {
            repeat += map[s[i]]++ == 1;
            repeat -= i >= 3 && --map[s[i - 3]] == 1;
            result += i >= 2 && repeat == 0;
        }
        return result;
    }
};

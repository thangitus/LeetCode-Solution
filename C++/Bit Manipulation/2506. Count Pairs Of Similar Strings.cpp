#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int similarPairs(vector<string> &words) {
        unordered_map<int, int> count;
        int res = 0;
        for (string &w: words) {
            int value = 0;
            for (char &c: w)
                value |= (1 << (c - 'a'));
            res += count[value];
            count[value]++;
        }
        return res;
    }
};

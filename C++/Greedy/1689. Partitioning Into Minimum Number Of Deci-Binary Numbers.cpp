#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (char c: n) res = max(res, c - '0');
        return res;
    }
};
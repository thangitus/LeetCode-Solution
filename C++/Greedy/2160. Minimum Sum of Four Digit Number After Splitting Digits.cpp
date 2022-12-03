#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ctoi(char c) {
        return c - '0';
    }

    int minimumSum(int num) {
        string s = to_string(num);
        std::sort(s.begin(), s.end());
        return (ctoi(s[0]) + ctoi(s[1])) * 10 + ctoi(s[2]) + ctoi(s[3]);
    }
};
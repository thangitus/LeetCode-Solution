#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sumOfNumberAndReverse(int n) {
        for (int i = 0; i <= n; ++i) {
            string s = to_string(i);
            std::reverse(s.begin(), s.end());
            if (i + stoi(s) == n) return true;
        }
        return false;
    }
};
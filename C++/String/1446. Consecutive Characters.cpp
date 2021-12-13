#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int result = 1, count = 1;
        char cur = s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == cur) count++;
            else count = 1, cur = s[i];
            result = max(result, count);
        }
        return result;
    }
};

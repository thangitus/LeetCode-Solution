#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTime(string time) {
        string h = time.substr(0, 2);
        string m = time.substr(3);
        int resH = 1, resM = 1;
        if (h[0] == h[1] && h[0] == '?') resH = 24;
        else if (h[0] == '?') {
            if (h[1] < '4') resH = 3;
            else resH = 2;
        } else if (h[1] == '?') {
            if (h[0] < '2') resH = 10;
            else resH = 4;
        }
        if (m[0] == m[1] && m[0] == '?') resM = 60;
        else if (m[0] == '?') resM = 6;
        else if (m[1] == '?') resM = 10;
        return resH * resM;
    }
};
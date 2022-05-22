#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (char c: s) count += c == letter;
        return (count * 1.0) / s.length() * 100;
    }
};
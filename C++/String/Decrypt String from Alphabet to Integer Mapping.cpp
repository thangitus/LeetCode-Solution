#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
 * */

class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        for (int i = s.length() - 1; i >= 0; i--) {
            int num;
            if (s[i] == '#') {
                num = stoi(s.substr(i - 2, 2));
                i -= 2;
            } else num = s[i] - '0';
            result += char(num + 'a' - 1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        string vowels = "aeiouAEIOU";
        for (int i = 0; i < s.length(); ++i) {
            if (vowels.find(s[i]) != string::npos) {
                if (i < s.length() / 2) count++;
                else count--;
            }
        }
        return count == 0;
    }
};

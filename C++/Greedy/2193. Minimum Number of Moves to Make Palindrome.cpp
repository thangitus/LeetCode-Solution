#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int result = 0;
        while (!s.empty()) {
            int i = s.find(s.back());
            if (i == s.size() - 1)
                result += i / 2;
            else result += i, s.erase(i, 1);
            s.pop_back();
        }
        return result;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCollisions(string s) {
        int n = s.length(), result = 0, right = 0, left = 0, count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == 'R') {
                if (s[i + 1] == 'L') result += 2 + right, right = 0, count++;
                else if (s[i + 1] == 'S') result += 1 + right, right = 0;
                else right++;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (s[i] == 'L') {
                if (s[i - 1] == 'R') result += 2 + left, left = 0;
                else if (s[i - 1] == 'S') result += 1 + left, left = 0;
                else left++;
            }
        }
        return result - count * 2;
    }
};

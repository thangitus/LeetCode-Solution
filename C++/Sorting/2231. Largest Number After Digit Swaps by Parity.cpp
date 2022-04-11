#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        for (int i = 0; i < s.length(); ++i)
            for (int j = i + 1; j < s.length(); ++j) {
                int a = s[i] - '0', b = s[j] - '0';
                if (a < b && !((a & 1) ^ (b & 1)))
                    swap(s[i], s[j]);
            }
        return stoi(s);
    }
};

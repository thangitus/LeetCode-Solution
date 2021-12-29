#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        for (char c: target)
            count += (c == '1' && count % 2 == 0)
                     || (c == '0' && count % 2);
        return count;
    }
};

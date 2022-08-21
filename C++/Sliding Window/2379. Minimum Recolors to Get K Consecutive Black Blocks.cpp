#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = INT_MAX, count = 0;
        for (int i = 0; i < blocks.size(); ++i) {
            count += blocks[i] == 'W';
            if (i >= k) count -= blocks[i - k] == 'W';
            if (i >= k - 1) res = min(res, count);

        }
        return res;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        for (int i = 0; i <= n; ++i) {
            int count = 0, cur = i;
            while (cur) {
                count += cur & 1;
                cur >>= 1;
            }
            result[i] = count;
        }
        return result;
    }
};

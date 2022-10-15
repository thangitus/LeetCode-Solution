#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>> &queries) {
        vector<int> powers;
        int mod = 1e9 + 7;
        for (int i = 0; i < 32; ++i)
            if (n & (1 << i)) powers.push_back(1 << i);
        vector<int> res;
        for (auto &q: queries) {
            long long product = 1;
            for (int i = q[0]; i <= q[1]; ++i)
                product *= powers[i], product %= mod;
            res.push_back(product);
        }
        return res;
    }
};

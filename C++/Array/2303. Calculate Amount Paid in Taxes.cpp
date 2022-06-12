#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>> &brackets, int income) {
        double res = 0;
        int cur = 0;
        for (auto &item: brackets) {
            int num = min(item[0], income);
            res += (double(num - cur) * ((double) item[1] / 100));
            cur = item[0];
            if (item[0] > income) break;
        }
        return res;
    }
};

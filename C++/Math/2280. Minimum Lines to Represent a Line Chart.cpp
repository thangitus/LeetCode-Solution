#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
        long long a = (long long) (x1) * (y2 - y3) +
                      (long long) x2 * (y3 - y1) +
                      (long long) x3 * (y1 - y2);
        return a == 0;
    }

    int minimumLines(vector<vector<int>> &prices) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), result = n - 1;
        for (int i = 2; i < n; ++i) {
            result -= checkCollinear(prices[i - 2][0], prices[i - 2][1],
                                     prices[i - 1][0], prices[i - 1][1],
                                     prices[i][0], prices[i][1]);
        }
        return result;
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        int n = items.size();
        vector<int> price(n), result(queries.size());
        unordered_map<int, int> beauties;
        sort(items.begin(), items.end());
        price[0] = items[0][0], beauties[price[0]] = items[0][1];
        for (int i = 1; i < n; ++i) {
            price[i] = items[i][0];
            beauties[price[i]] = max(items[i][1], beauties[price[i - 1]]);
        }
        for (int i = 0; i < queries.size(); ++i) {
            auto index = lower_bound(price.begin(), price.end(), queries[i]) - price.begin();
            if (index >= n || price[index] > queries[i])
                index--;
            if (index >= 0 && price[index] <= queries[i])
                result[i] = beauties[price[index]];
        }
        return result;
    }
};

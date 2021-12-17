#include <bits/stdc++.h>

using namespace std;

class Solution {
    map<int, int, greater<>> map;

    bool isValid(int k, int orders) {
        for (auto &[num, count]: map) {
            if (num < k) break;
            orders -= count * (num - k);
            if (orders <= 0) return true;
        }
        return false;
    }

public:
    int maxProfit(vector<int> &inventory, int orders) {
        long result = 0, mod = 1e9 + 7, left = 0, right = *max_element(inventory.begin(), inventory.end());
        for (int n: inventory) map[n]++;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (isValid(mid, orders)) left = mid + 1;
            else right = mid - 1;
        }
        for (auto &[num, count]: map) {
            if (num < left) break;
            orders -= count * (num - left);
            result += ((num + left + 1) * (num - left) / 2 % mod * count % mod) % mod;
        }
        if (orders) result = (result + left * orders % mod) % mod;
        return result;
    }
};

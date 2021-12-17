#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<>());
        long result = 0, mod = 1e9 + 7, cur = inventory[0], i = 0, n = inventory.size();
        while (orders) {
            while (i < n && inventory[i] == cur)i++;
            long next = i == n ? 0 : inventory[i], h = cur - next, r = 0;
            if (i * h > orders) {
                h = orders / i;
                r = orders % i;
                orders = 0;
            } else orders -= i * h;
            long val = cur - h;
            result = (result + (cur + val + 1) * h / 2 * i + val * r) % mod;
            cur = next;
        }
        return result;
    }
};

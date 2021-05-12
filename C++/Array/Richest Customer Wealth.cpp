#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/richest-customer-wealth/
class Solution {
public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int ans = 0;
        for (auto &account:accounts)
            ans = max(ans, accumulate(account.begin(), account.end(), 0));
        return ans;
    }
};
#include <bits/stdc++.h>

using namespace std;
/**
 * https://leetcode.com/problems/maximum-earnings-from-taxi/
 * */

class Solution {
private:
    static bool compare(vector<int> &ride1, vector<int> &ride2) {
        if (ride1[1] != ride2[1]) return ride1[1] < ride2[1];
        return ride1[2] > ride2[2];
    }

    static int profit(vector<int> &ride) {
        return ride[1] - ride[0] + ride[2];
    }

public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        sort(rides.begin(), rides.end(), compare);
        vector<long long> dp(n + 1);
        for (int i = 1, j = 0; i <= n; i++) {
            dp[i] = dp[i - 1];
            while (j < rides.size() && rides[j][1] < i)j++;
            while (j < rides.size() && rides[j][1] == i)
                dp[i] = max(dp[i], dp[rides[j][0]] + profit(rides[j++]));
        }
        return dp[n];
    }
};

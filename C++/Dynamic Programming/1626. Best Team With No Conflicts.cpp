#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size(), result = 0;
        vector<pair<int, int>> players(n);
        for (int i = 0; i < n; ++i) {
            players[i].first = ages[i];
            players[i].second = scores[i];
        }
        sort(players.begin(), players.end());
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            int score = players[i].second;
            dp[i] = score;
            for (int j = 0; j < i; ++j)
                if (players[j].second <= score)
                    dp[i] = max(dp[i], score + dp[j]);
            result = max(result, dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

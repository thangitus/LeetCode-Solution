#include <bits/stdc++.h>


using namespace std;

/**
 * https://leetcode.com/problems/parallel-courses-iii/
 * */
class Solution {
public:
    int solve(int u, vector<vector<int>> &graph, vector<int> &dp, vector<int> &time) {
        if (dp[u] != -1) return dp[u];
        dp[u] = time[u];
        for (int v:graph[u])
            dp[u] = max(dp[u], time[u] + solve(v, graph, dp, time));
        return dp[u];
    }

    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        vector<vector<int>> graph(n);
        vector<int> dp(n, -1);
        for (auto &e:relations) {
            int u = e[0] - 1, v = e[1] - 1;
            graph[v].push_back(u);
        }

        int result = 0;
        for (int i = 0; i < n; i++)
            result = max(result, solve(i, graph, dp, time));
        return result;
    }
};
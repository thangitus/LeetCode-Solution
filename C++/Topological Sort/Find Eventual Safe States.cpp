#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-eventual-safe-states/
 * */

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &g) {
        unsigned int n = g.size();
        vector<int> degree(n), result;
        vector<vector<int>> graph(n);
        queue<int> queue;
        for (int i = 0; i < n; i++) {
            for (int &v:g[i])
                graph[v].push_back(i);
        }
        for (int i = 0; i < n; i++)
            for (int &v:graph[i]) degree[v]++;
        for (int i = 0; i < n; i++)
            if (!degree[i]) queue.push(i);
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            result.push_back(u);
            for (int &v:graph[u])
                if (--degree[v] == 0) queue.push(v);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

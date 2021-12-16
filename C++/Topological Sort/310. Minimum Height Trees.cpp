#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        queue<int> queue;
        vector<vector<int>> graph(n);
        vector<int> degree(n), result;
        for (auto &edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++, degree[v]++;
        }
        for (int i = 0; i < n; i++)
            if (degree[i] == 1) queue.push(i);
        while (!queue.empty()) {
            result.clear();
            for (int i = queue.size(); i > 0; i--) {
                int u = queue.front();
                queue.pop();
                result.push_back(u);
                for (int &v: graph[u])
                    if (--degree[v] == 1) queue.push(v);
            }
        }
        return result;
    }
};

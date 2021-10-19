#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/number-of-provinces/
 */

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size(), result = 0;
        vector<vector<int>> graph(n);
        vector<bool> visited(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j])
                    graph[i].push_back(j);
        for (int i = 0; i < n; i++)
            if (!visited[i]) {
                result++;
                dfs(graph, visited, i);
            }
        return result;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u) {
        visited[u] = true;
        for (int &v:graph[u])
            if (!visited[v])
                dfs(graph, visited, v);

    }
};
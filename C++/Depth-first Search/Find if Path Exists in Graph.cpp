#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-if-path-exists-in-graph/
 * */

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for (auto &edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(graph, visited, start, end);
    }

    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int start, int &end) {
        if (start == end) return true;
        visited[start] = true;
        for (int &v:graph[start])
            if (!visited[v] && dfs(graph, visited, v, end))
                return true;
        return false;
    }
};

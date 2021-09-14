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
        queue<int> queue;
        for (auto &edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue.push(start), visited[start] = true;
        while (!queue.empty()) {
            int u = queue.front();
            if (u == end) return true;
            queue.pop();
            for (int &v:graph[u])
                if (!visited[v]) {
                    queue.push(v);
                    visited[v] = true;
                }
        }
        return false;
    }
};

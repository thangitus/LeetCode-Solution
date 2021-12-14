#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
        vector<vector<int>> graph(n);
        for (auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(graph, hasApple, -1, 0);
    }

    int dfs(vector<vector<int>> &graph, vector<bool> &hasApple, int parent, int cur) {
        int sum = 0;
        for (int u: graph[cur]) {
            if (u != parent) {
                int child = dfs(graph, hasApple, cur, u);
                if (child) sum += child;
            }
        }
        int dist = cur == 0 ? 0 : 2;
        return (sum != 0 || hasApple[cur]) ? sum + dist : 0;
    }
};

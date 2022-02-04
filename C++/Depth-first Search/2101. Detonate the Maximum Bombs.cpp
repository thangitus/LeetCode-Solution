#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        vector<vector<int>> graph(bombs.size());
        for (int i = 0; i < bombs.size(); ++i)
            for (int j = 0; j < bombs.size(); ++j) {
                if (i == j) continue;
                long dx = bombs[i][0] - bombs[j][0], dy = bombs[i][1] - bombs[j][1];
                long dist = dx * dx + dy * dy;
                if (dist <= (long) bombs[i][2] * bombs[i][2])
                    graph[i].push_back(j);
            }
        int result = 0;
        for (int i = 0; i < bombs.size(); ++i) {
            vector<bool> visited(bombs.size());
            result = max(result, dfs(graph, visited, i));
        }
        return result;
    }

    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int u) {
        if (visited[u]) return 0;
        visited[u] = true;
        int result = 1;
        for (int &v: graph[u])
            result += dfs(graph, visited, v);
        return result;
    }
};

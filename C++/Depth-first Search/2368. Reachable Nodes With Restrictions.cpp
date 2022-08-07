#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &r) {
        vector<vector<int>> graph(n);
        unordered_set<int> restricted(r.begin(), r.end());
        if (restricted.count(0)) return 0;
        for (auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(graph, restricted, 0);
    }

    int dfs(vector<vector<int>> &graph, unordered_set<int> &restricted, int cur) {
        restricted.insert(cur);
        int res = 0;
        for (int &neighbor: graph[cur]) {
            if (restricted.count(neighbor)) continue;
            res += dfs(graph, restricted, neighbor);
        }
        return res + 1;
    }
};
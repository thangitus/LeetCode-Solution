#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> result;

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
        vector<vector<int>> graph(n);
        result.resize(n);
        for (auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(graph, labels, -1, 0);
        return result;
    }

    vector<int> dfs(vector<vector<int>> &graph, string &labels, int parent, int u) {
        vector<int> count(26);
        count[labels[u] - 'a']++;
        for (int v: graph[u])
            if (v != parent) {
                auto child = dfs(graph, labels, u, v);
                for (int i = 0; i < 26; i++)
                    count[i] += child[i];
            }
        result[u] = count[labels[u] - 'a'];
        return count;
    }
};

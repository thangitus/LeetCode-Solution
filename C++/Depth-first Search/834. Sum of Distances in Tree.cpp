#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dist, countChild;
    vector<vector<int>> graph;
    int n;

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        this->n = n;
        countChild.resize(n, 1);
        dist.resize(n);
        graph.resize(n);
        for (auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(-1, 0);
        dfs2(-1, 0);
        return dist;
    }

    /**
     * Calculate all child node of cur nodes <p>
     * and distance from cur node to all child nodes
     * */
    void dfs(int parent, int cur) {
        for (int child: graph[cur])
            if (child != parent) {
                dfs(cur, child);
                countChild[cur] += countChild[child];
                dist[cur] += dist[child] + countChild[child];
            }
    }

    void dfs2(int parent, int cur) {
        for (int child: graph[cur])
            if (child != parent) {
                int numOtherNode = n - countChild[child];
                // dist[cur] - countChild[child] =
                // distance from child to all grandchild + distance from cur to all others children
                dist[child] = dist[cur] - countChild[child] + numOtherNode;
                dfs2(cur, child);
            }
    }
};

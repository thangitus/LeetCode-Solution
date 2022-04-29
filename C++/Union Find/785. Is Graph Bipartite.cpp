#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> parents;

    int findSet(int u) {
        return parents[u] < 0 ? u :
                parents[u] = findSet(parents[u]);
    }

    void unionSet(int u, int v) {
        int pu = findSet(u), pv = findSet(v);
        if (pu != pv) parents[pu] = pv;
    }

    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        parents.resize(n + 2, -1);
        for (int i = 0; i < n; ++i) {
            for (int &u: graph[i]) {
                if (findSet(u) == findSet(i))
                    return false;
                unionSet(u, graph[i][0]);
            }
        }
        return true;
    }
};

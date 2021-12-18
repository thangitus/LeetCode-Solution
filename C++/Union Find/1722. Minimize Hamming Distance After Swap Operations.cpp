#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> parents;

    int findSet(int u) {
        return parents[u] < 0 ? u :
                parents[u] = findSet(parents[u]);
    }

    void unionSet(int u, int v) {
        int pu = findSet(u), pv = findSet(v);
        if (pu != pv) parents[pv] = pu;
    }

public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
        int n = source.size(), result = 0;
        parents.resize(n, -1);
        for (auto &allowedSwap: allowedSwaps)
            unionSet(allowedSwap[0], allowedSwap[1]);
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
            graph[findSet(i)].push_back(i);
        for (auto &ids: graph) {
            unordered_map<int, int> map;
            for (int id: ids)
                map[source[id]]++, map[target[id]]--;
            for (auto &item: map)
                result += abs(item.second);

        }
        return result / 2;
    }
};

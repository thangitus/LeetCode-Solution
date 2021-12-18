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
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int len = s.length();
        parents.resize(len, -1);
        for (auto &pair: pairs)
            unionSet(pair[0], pair[1]);
        vector<vector<int>> graph(len);
        for (int i = 0; i < len; i++)
            graph[findSet(i)].push_back(i);
        for (auto &ids: graph) {
            string tmp;
            for (int id: ids)
                tmp += s[id];
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < ids.size(); i++)
                s[ids[i]] = tmp[i];
        }
        return s;
    }
};


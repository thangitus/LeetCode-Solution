#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/graph-connectivity-with-threshold/
 */

class Solution {
private:
    vector<int> parents;

    int findSet(int u) {
        if (parents[u] != u)
            parents[u] = findSet(parents[u]);
        return parents[u];
    }

    void unionSet(int u, int v) {
        int pu = findSet(u), pv = findSet(v);
        parents[pv] = pu;
    }

public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries) {
        parents.resize(10001);
        for (int i = 0; i < parents.size(); i++) parents[i] = i;
        for (int num = 1; num <= n; num++)
            for (int i = threshold + 1; i * 2 <= num; i++)
                if (num % i == 0)
                    unionSet(num, i);
        vector<bool> result;
        for (auto &query: queries)
            result.push_back(findSet(query[0]) == findSet(query[1]));
        return result;
    }
};

#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/satisfiability-of-equality-equations/
 */



class Solution {
private:
    int n;
    vector<int> parent;
    vector<int> ranks;

    int findSet(int u) {
        if (parent[u] != u)
            parent[u] = findSet(parent[u]);
        return parent[u];
    }

    void unionSet(int u, int v) {
        int pu = findSet(u), pv = findSet(v);
        if (pu == pv) return;
        if (ranks[pu] < ranks[pv]) parent[pu] = pv;
        else if (ranks[pu] > ranks[pv])
            parent[pv] = pu;
        else {
            parent[pu] = pv;
            ranks[pv]++;
        }
    }

public:
    bool equationsPossible(vector<string> &equations) {
        n = 128;
        parent.resize(n);
        ranks.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            ranks[i] = 0;
        }
        for (auto &equation:equations)
            if (equation[1] == '=')
                unionSet(equation[0], equation[3]);
        for (auto &equation:equations)
            if (equation[1] == '!') {
                int pa = findSet(equation[0]), pb = findSet(equation[3]);
                if (pa == pb) return false;
            }
        return true;
    }
};

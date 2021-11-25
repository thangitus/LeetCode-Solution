#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
 */

class Solution {
private:
    vector<int> alice;
    vector<int> bob;

    int findSet(vector<int> &parents, int u) {
        if (parents[u] != u)
            parents[u] = findSet(parents, parents[u]);
        return parents[u];
    }

    void unionSet(vector<int> &parents, int u, int v) {
        int pu = findSet(parents, u), pv = findSet(parents, v);
        parents[pv] = pu;
    }

    bool isConnected(vector<int> &parents, int u, int v) {
        return findSet(parents, u) == findSet(parents, v);
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        alice.resize(n + 1);
        bob.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            alice[i] = i;
            bob[i] = i;
        }

        int result =0;
        for (auto &edge: edges) {
            if (edge[0] != 3) continue;
            int u = edge[1], v = edge[2];
            if (isConnected(bob, u, v) && isConnected(alice, u, v))
                result++;
            if (!isConnected(alice, u, v)) unionSet(alice, u, v);
            if (!isConnected(bob, u, v)) unionSet(bob, u, v);
        }
        for (auto &edge: edges) {
            if (edge[0] == 3) continue;
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 1) {
                if (isConnected(alice, u, v)) result++;
                else unionSet(alice, u, v);
            } else {
                if (isConnected(bob, u, v)) result++;
                else unionSet(bob, u, v);
            }
        }
        int pBob = findSet(bob, 1), pAlice = findSet(alice, 1);
        for (int i = 1; i <= n; i++) {
            if (findSet(bob, i) != pBob) return -1;
            if (findSet(alice, i) != pAlice) return -1;
        }
        return result;
    }
};

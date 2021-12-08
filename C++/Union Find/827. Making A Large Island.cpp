#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> parents, size;

    void makeSet(int n) {
        parents.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parents[i] = i;
    }

    int findSet(int u) {
        if (parents[u] != u)
            parents[u] = findSet(parents[u]);
        return parents[u];
    }

    int connect(int u, int v) {
        int pu = findSet(u), pv = findSet(v);
        if (pu == pv) return pu;
        if (size[pu] >= size[pv]) {
            parents[pv] = pu;
            size[pu] += size[pv];
            return pu;
        } else {
            parents[pu] = pv;
            size[pv] += size[pu];
            return pv;
        }
    }

    vector<int> getNeighbors(vector<vector<int>> &grid, int i, int j) {
        const int dx[]{-1, 0, 0, 1};
        const int dy[]{0, -1, 1, 0};
        vector<int> neighbor;
        int n = grid.size();
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
            if (grid[x][y]) neighbor.push_back(x * n + y);
        }
        return neighbor;
    }

public:
    int largestIsland(vector<vector<int>> &grid) {
        int n = grid.size(), result = 0;
        makeSet(n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) continue;
                int u = i * n + j;
                for (int v: getNeighbors(grid, i, j))
                    connect(u, v);
                result = max(result, size[findSet(u)]);
            }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) continue;
                int count = 1;
                auto neighbors = getNeighbors(grid, i, j);
                unordered_set<int> parent;
                for (int v: neighbors)
                    parent.insert(findSet(v));
                for (int p: parent)
                    count += size[p];
                result = max(result, count);
            }
        return result;
    }
};

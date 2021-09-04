#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sum-of-distances-in-tree/
 * Floyd warshall algorithm
 * Not accepted
 * */

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto &edge:edges) {
            dist[edge[0]][edge[1]] = 1;
            dist[edge[1]][edge[0]] = 1;
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        vector<int> result(n);
        for (int i = 0; i < n; i++)
            result[i] = accumulate(dist[i].begin(), dist[i].end(), 0);
        return result;
    }
};
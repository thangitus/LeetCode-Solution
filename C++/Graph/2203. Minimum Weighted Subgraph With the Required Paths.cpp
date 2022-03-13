#include <bits/stdc++.h>

using namespace std;

typedef long long long2;

class Solution {
    vector<vector<pair<long2, long2>>> graph;
    int n;

    struct option {
        bool operator()(const pair<long2, long2> &a, const pair<long2, long2> &b) {
            return a.second > b.second;
        }
    };

    void dijkstra(int x, vector<long2> &dist) {
        dist.clear();
        dist.resize(n, 1e12);
        priority_queue<pair<long2, long2>, vector<pair<long2, long2>>, option> queue;
        queue.push(make_pair(x, 0));
        dist[x] = 0;
        while (!queue.empty()) {
            auto top = queue.top();
            queue.pop();
            long2 u = top.first;
            long2 w = top.second;
            if (dist[u] != w) continue;
            for (auto neighbor: graph[u]) {
                if (w + neighbor.second < dist[neighbor.first]) {
                    dist[neighbor.first] = w + neighbor.second;
                    queue.push(make_pair(neighbor.first, dist[neighbor.first]));
                }
            }
        }
    }

public:
    long2 minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest) {
        this->n = n;
        graph.resize(n);
        for (auto &edge: edges)
            graph[edge[0]].push_back({edge[1], edge[2]});
        vector<long2> dist1, dist2, dist3;
        dijkstra(src2, dist2);
        dijkstra(src1, dist1);
        graph.clear();
        graph.resize(n);
        for (auto &edge: edges)
            graph[edge[1]].push_back({edge[0], edge[2]});
        dijkstra(dest, dist3);
        long2 result = 1e12;
        for (int i = 0; i < n; i++) {
            auto iToDest = dist3[i];
            auto src1ToI = dist1[i];
            auto src2ToI = dist2[i];
            result = min({result, src1ToI + iToDest + src2ToI});
        }
        if (result >= 1e12) result = -1;
        return result;

    }
};
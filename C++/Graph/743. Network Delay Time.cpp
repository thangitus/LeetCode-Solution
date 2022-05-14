#include <bits/stdc++.h>

using namespace std;

class Solution {

    struct option {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        }
    };

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &time: times)
            graph[time[0]].push_back({time[1], time[2]});

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, option> queue;
        dist[k] = 0;
        queue.push({k, dist[k]});
        while (!queue.empty()) {
            auto top = queue.top();
            queue.pop();
            int u = top.first, w = top.second;
            for (auto &neighbor: graph[u]) {
                int v = neighbor.first;
                if (w + neighbor.second < dist[v]) {
                    dist[v] = w + neighbor.second;
                    queue.push({v, dist[v]});
                }
            }
        }
        int res = *max_element(dist.begin() + 1, dist.end());
        return res != INT_MAX ? res : -1;
    }
};

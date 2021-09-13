#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        queue<pair<int, int>> queue;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue.push({src, 0});
        for (auto &flight:flights)
            graph[flight[0]].push_back({flight[1], flight[2]});
        while (!queue.empty() && 0 <= k--) {
            for (int i = queue.size(); i > 0; i--) {
                auto cur = queue.front();
                queue.pop();
                for (auto &neighbor:graph[cur.first]) {
                    if (dist[neighbor.first] > cur.second + neighbor.second) {
                        dist[neighbor.first] = cur.second + neighbor.second;
                        queue.push({neighbor.first, dist[neighbor.first]});
                    }
                }
            }
        }
        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};

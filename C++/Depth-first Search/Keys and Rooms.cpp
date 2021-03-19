#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        return dfs(rooms, visited, 0) == n;
    }

    int dfs(vector<vector<int>> &rooms, vector<bool> &visited, int cur) {
        int res = 1;
        for (int &i:rooms[cur])
            if (!visited[i]) {
                visited[i] = true;
                res += dfs(rooms, visited, i);
            }
        return res;
    }
};
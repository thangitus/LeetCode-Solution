#include <bits/stdc++.h>

using namespace std;

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

    void reset(int u) {
        parents[u] = u;
    }

    bool connected(int u, int v) {
        return findSet(u) == findSet(v);
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) { return a[2] < b[2]; });
        parents.resize(n);
        for (int i = 0; i < n; i++) parents[i] = i;
        int i = 0, m = meetings.size();
        unionSet(0, firstPerson);
        vector<int> group;
        while (i < m) {
            group.clear();
            int time = meetings[i][2];
            while (i < m && meetings[i][2] == time) {
                int u = meetings[i][0], v = meetings[i][1];
                unionSet(u, v);
                group.push_back(u);
                group.push_back(v);
                i++;
            }
            for (int u: group)
                if (!connected(0, u))
                    reset(u);
        }
        vector<int> result;
        for (int u = 0; u < n; u++)
            if (connected(0, u))
                result.push_back(u);
        return result;
    }
};
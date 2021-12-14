#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        unordered_map<int, vector<int>> map;
        for (auto &item: adjacentPairs) {
            map[item[0]].push_back(item[1]);
            map[item[1]].push_back(item[0]);
        }
        vector<int> result;
        int head, prev;
        for (auto &item: map)
            if (item.second.size() == 1) {
                head = item.first;
                break;
            }
        result.push_back(head);
        prev = head;
        head = map[head][0];
        while (true) {
            result.push_back(head);
            if (map[head].size() == 1) break;
            int tmp = head;
            head = map[head][0] != prev ? map[head][0] : map[head][1];
            prev = tmp;
        }
        return result;
    }
};

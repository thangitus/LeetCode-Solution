#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank) {
        int res = 0;
        queue<string> queue;
        unordered_set<string> visited{start};
        queue.push(start);
        while (!queue.empty()) {
            for (int k = queue.size(); k > 0; --k) {
                auto cur = queue.front();
                queue.pop();
                if (cur == end) return res;
                for (string &b: bank) {
                    if (visited.count(b)) continue;
                    int diff = 0;
                    for (int i = 0; i < cur.length(); ++i) diff += (cur[i] != b[i]);
                    if (diff == 1) queue.push(b), visited.insert(b);
                }
            }
            res++;
        }
        return -1;
    }
};

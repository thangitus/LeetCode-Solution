#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/path-crossing/
 * */

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> set;
        pair<int, int> curr{0, 0};
        set.insert(make_pair(curr.first, curr.second));
        for (char ch:path) {
            if (ch == 'N') curr.second++;
            if (ch == 'S') curr.second--;
            if (ch == 'E') curr.first++;
            if (ch == 'W') curr.first--;
            if (set.find(curr) != set.end()) return true;
            set.insert(curr);
        }
        return false;
    }
};
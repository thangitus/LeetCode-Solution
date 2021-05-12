#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/rabbits-in-forest/
 * If the rabbit answers k, including it, we get k + 1 rabbit
 * if k + 1 rabbit answers the same value, they are talking about each other
 * */

class Solution {
public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> map;
        for (int &i:answers)map[i]++;
        int ans = 0;
        for (auto &i:map) {
            int k = i.first, v = i.second;
            ans += ceil((float) v / (k + 1)) * (k + 1);
        }
        return ans;
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string bestHand(vector<int> &ranks, vector<char> &suits) {
        unordered_set<char> set;
        unordered_map<int, int> map;
        int maxRank = 0;
        for (int i = 0; i < 5; ++i)
            set.insert(suits[i]), maxRank = max(maxRank, ++map[ranks[i]]);
        if (set.size() == 1) return "Flush";
        else if (maxRank >= 3) return "Three of a Kind";
        else if (maxRank == 2) return "Pair";
        else return "High Card";
    }
};
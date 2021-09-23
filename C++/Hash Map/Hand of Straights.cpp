#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/hand-of-straights/
 * */

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        unordered_map<int, int> count;
        for (int &num:hand)count[num]++;
        sort(hand.begin(), hand.end());
        for (int &num:hand) {
            if (!count[num]) continue;
            for (int i = 0; i < groupSize; i++)
                if (!count[num + i]) return false;
                else count[num + i]--;
        }
        return true;
    }
};

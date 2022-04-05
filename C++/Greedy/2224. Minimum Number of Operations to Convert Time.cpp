#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int curTime = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int correctTime = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int diff = correctTime - curTime;
        int result = 0, ops[]{60, 15, 5, 1};
        for (int &op: ops)
            result += diff / op, diff %= op;
        return result;
    }
};

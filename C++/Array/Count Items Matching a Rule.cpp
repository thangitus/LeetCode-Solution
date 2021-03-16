#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/count-items-matching-a-rule/
class Solution {
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue) {
        int res = 0;
        for (auto &item:items) {
            if (ruleKey == "type" && item[0] == ruleValue) res++;
            else if (ruleKey == "color" && item[1] == ruleValue)res++;
            else if (ruleKey == "name" && item[2] == ruleValue) res++;
        }
        return res;
    }
};
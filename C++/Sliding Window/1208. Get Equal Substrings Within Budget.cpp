#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.length(), cost[len], result = 0, curCost = 0, left = 0;
        for (int i = 0; i < len; i++)
            cost[i] = abs(s[i] - t[i]);
        for (int i = 0; i < len; i++) {
            curCost += cost[i];
            while (left <= i && curCost > maxCost)
                curCost -= cost[left++];
            result = max(result, i - left + 1);
        }
        return result;
    }
};

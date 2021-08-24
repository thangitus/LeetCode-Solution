#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-largest-group/
 * */

class Solution {
public:
    int sum(int n) {
        return n == 0 ? 0 : n % 10 + sum(n / 10);
    }

    int countLargestGroup(int n) {
        vector<int> count(37);
        int maxFrequency = 0, res = 0;
        for (int i = 1; i <= n; i++)
            maxFrequency = max(maxFrequency, ++count[sum(i)]);
        for (int i = 0; i < 37; i++)
            res += count[i] == maxFrequency;
        return res;
    }
};

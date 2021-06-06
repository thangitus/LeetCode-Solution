#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/submissions/
 * */

class Solution {
public:
    int reductionOperations(vector<int> &nums) {
        map<int, int>::iterator it;
        map<int, int> map;
        for (int &i:nums) map[i]++;
        int prev, ans;
        prev = ans = 0;
        for (it = map.end(); it != map.begin(); it--) {
            if (it == map.end()) continue;
            ans += it->second + prev;
            prev += it->second;
        }
        return ans;
    }
};
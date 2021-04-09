#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/fruit-into-baskets/
 */

class Solution {
public:
    int totalFruit(vector<int> &tree) {
        int ans, i, count;
        ans = i = count = 0;
        unordered_map<int, int> map;
        for (int j = 0; j < tree.size(); j++) {
            if (!map[tree[j]]) count++;
            map[tree[j]]++;
            while (count > 2) {
                map[tree[i]]--;
                if (!map[tree[i]]) count--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
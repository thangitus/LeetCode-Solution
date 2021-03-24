#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/advantage-shuffle/
 */
class Solution {
public:
    vector<int> advantageCount(vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<int> res(n);
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++)
            pairs[i] = make_pair(b[i], i);
        sort(a.begin(), a.end());
        sort(pairs.begin(), pairs.end());
        int i, l, r;
        i = l = 0;
        r = n - 1;
        while (i < n) {
            if (a[i] > pairs[l].first) {
                res[pairs[l].second] = a[i];
                l++;
            } else {
                res[pairs[r].second] = a[i];
                r--;
            }
            i++;
        }
        return res;
    }
};
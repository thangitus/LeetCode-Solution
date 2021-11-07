#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
 * */

class Solution {
public:
    string kthDistinct(vector<string> &arr, int k) {
        unordered_map<string, int> count;
        for (auto &s:arr) count[s]++;
        for (auto &s:arr) {
            if (count[s] == 1) k--;
            if (k == 0) return s;
        }
        return "";
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/partition-labels/
 * */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> pos(26), result;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
            pos[s[i] - 'a'] = i;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, pos[s[i] - 'a']);
            if (end == i) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};

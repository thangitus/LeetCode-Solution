#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string> &strs) {
        int count = 0;
        for (int j = 0; j < strs[0].length(); ++j) {
            for (int i = 1; i < strs.size(); ++i)
                if (strs[i][j] < strs[i - 1][j]) {
                    count++;
                    break;
                }
        }
        return count;
    }
};

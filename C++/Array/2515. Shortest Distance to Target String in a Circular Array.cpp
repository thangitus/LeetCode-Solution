#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closetTarget(vector<string> &words, string target, int startIndex) {
        int n = words.size(), res = INT_MAX;
        for (int i = 0; i < n; ++i)
            if (words[i] == target) {
                int pos = min(abs(i - startIndex), n - abs(i - startIndex));
                res = min(res, pos);
            }
        return res == INT_MAX ? -1 : res;
    }
};
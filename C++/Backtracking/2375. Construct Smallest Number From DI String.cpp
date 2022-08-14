#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string cur = "";
        unordered_set<int> used;
        return backtracking(pattern, cur, used, -1);
    }

    string backtracking(string &pattern, string &cur, unordered_set<int> &used, int i) {
        if (i == pattern.length()) return cur;
        string res;
        for (int k = 1; k <= 9; ++k) {
            if (used.count(k)) continue;
            char chr = char(k + '0');
            cur += chr;
            used.insert(k);

            if (i == -1) {
                res = backtracking(pattern, cur, used, i + 1);
            } else {
                char prev = cur[cur.size() - 2];
                if ((pattern[i] == 'I' && chr > prev) || (pattern[i] == 'D' && chr < prev))
                    res = backtracking(pattern, cur, used, i + 1);
            }

            used.erase(k);
            cur.pop_back();
            if (!res.empty()) return res;
        }
        return "";
    }
};
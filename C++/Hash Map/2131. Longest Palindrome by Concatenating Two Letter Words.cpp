#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string> &words) {
        int count = 0;
        unordered_map<string, int> map;
        for (string &w: words) {
            string reversed = w;
            reverse(reversed.begin(), reversed.end());
            if (map[reversed]) count += 4, map[reversed]--;
            else map[w]++;
        }
        for (auto &w: map)
            if (w.second && w.first[0] == w.first[1]) {
                count += 2;
                break;
            }
        return count;
    }
};
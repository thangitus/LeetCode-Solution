#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> count;
        for (char &c: s) count[c]++;
        int left = 0, n = s.length(), k = n / 4, res = n;
        for (int i = 0; i < n; ++i) {
            count[s[i]]--;
            while (left < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                res = min(res, i - left + 1);
                count[s[left++]]++;
            }
        }
        return res;
    }
};

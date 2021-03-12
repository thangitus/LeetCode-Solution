#include <bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int l = s.length();
        if (l < k) return false;
        unordered_set<string> set;
        for (int i = 0; i <= l - k; i++) {
            string str = s.substr(i, k);
            set.insert(str);
        }
        return set.size() == 1 << k; // 1<<k == pow(2,k)
    }
};

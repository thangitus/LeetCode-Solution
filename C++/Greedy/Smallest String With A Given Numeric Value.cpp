#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
 * */

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        while (n--) {
            int remain = k - n;
            remain = min(remain, 26);
            ans += char(remain + 'a' - 1);
            k -= remain;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

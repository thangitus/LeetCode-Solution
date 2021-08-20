#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/add-binary/
 * */

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
        string ans;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            ans += char(carry % 2 + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

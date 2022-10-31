#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        string s = to_string(n), res;
        int curSum = 0, remain = 0;
        for (char &c: s) curSum += (c - '0');
        for (int i = s.length() - 1; i >= 0 && curSum > target; --i) {
            int digit = s[i] - '0', sum = digit + remain, add = 10 - sum;
            s[i] = char(sum % 10 + '0');
            remain = sum / 10;
            if (s[i] == '0') {
                curSum -= digit;
                res += '0';
                continue;
            }
            s[i] = '0', curSum -= sum - 1, remain = 1, res += char(add + '0');
        }
        if (curSum > target) res += char(10 - (s[0] - '0' + remain) + '0');
        reverse(res.begin(), res.end());
        return res.empty() ? 0 : stoll(res);
    }
};

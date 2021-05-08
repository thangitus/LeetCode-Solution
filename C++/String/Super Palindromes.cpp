#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/super-palindromes/
 * */

typedef unsigned long long ll;
class Solution {
private:
    bool isPalindrome(ll &num) {
        return num == reverse(num);
    }

    ll reverse(ll num) {
        long ans = 0;
        while (num) {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        return ans;
    }

public:
    int superpalindromesInRange(string left, string right) {
        int ans = 0;
        ll l = stol(left), r = stol(right);

        for (int i = 1; i < 100000; i++) {
            string str = to_string(i);
            for (int j = str.length() - 2; j >= 0; j--) // 35 -> 353
                str += str[j];
            ll num = stol(str);
            num *= num;
            if (num > r) break;
            if (num >= l && isPalindrome(num)) ans++;
        }

        for (int i = 1; i < 100000; i++) {
            string str = to_string(i);
            for (int j = str.length() - 1; j >= 0; j--)  // 35 -> 3553
                str += str[j];
            ll num = stol(str);
            num *= num;
            if (num > r) break;
            if (num >= l && isPalindrome(num)) ans++;
        }
        return ans;
    }
};
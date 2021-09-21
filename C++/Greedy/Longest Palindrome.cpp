#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-palindrome/
 * */

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> arr(255);
        int res = 0;
        for (char &c : s) {
            arr[c]++;
            if (arr[c] == 2) {
                res += 2;
                arr[c] = 0;
            }
        }
        for (int& i : arr)
            if (i) {
                res++;
                break;
            }
        return res;
    }
};

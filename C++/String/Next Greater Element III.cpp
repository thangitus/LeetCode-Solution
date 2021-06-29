#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/next-greater-element-iii/
 * */

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n); //9652543
        int i = s.size() - 2;
        for (; i >= 0; i--)
            if (s[i + 1] > s[i]) break;
        if (i == -1) return -1; //i=3
        for (int j = s.size() - 1; j > i; j--)
            if (s[j] > s[i]) {
                swap(s[i], s[j]);
                break;
            }
        //s = 9653542
        reverse(s.begin() + i + 1, s.end()); // s = 9653245
        long ans = stol(s);
        return ans > INT_MAX ? -1 : ans;
    }
};
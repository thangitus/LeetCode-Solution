#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/shifting-letters/
 * */

class Solution {
public:
    string shiftingLetters(string s, vector<int> &shifts) {
        int n = shifts.size();
        vector<long long> sums(n);
        sums[n - 1] = shifts[n - 1];
        for (int i = n - 2; i >= 0; i--)sums[i] = sums[i + 1] + shifts[i];
        for (int i = 0; i < n; i++)
            s[i] = char((s[i] - 'a' + sums[i]) % 26 + 'a');
        return s;
    }
};

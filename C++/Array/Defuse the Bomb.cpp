#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/defuse-the-bomb/
 */

class Solution {
public:
    vector<int> decrypt(vector<int> &code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0) return ans;
        int sum = 0, left = 1, right = k;
        if (k < 0) {
            k *= -1;
            left = n - k;
            right = n - 1;
        }
        for (int i = left; i <= right; i++) sum += code[i];
        for (int i = 0; i < n; i++) {
            ans[i] = sum;
            sum -= code[left++ % n];
            sum += code[++right % n];
        }
        return ans;
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/unique-binary-search-trees/
 * Refs: https://www.youtube.com/watch?v=OIc0mHgHUww
 * numTree(4) =  numTree(0) * numTree(3) (choose 1 is root, so leftTree have 0 node, and rightTree have 3 nodes (2,3,4))
 *             + numTree(1) * numTree(2) (choose 2 is root)
 *             + numTree(2) * numTree(1) (choose 3 is root)
 *             + numTree(3) * numTree(0) (choose 4 is root)
 * */

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - j - 1];
        return dp[n];
    }
};

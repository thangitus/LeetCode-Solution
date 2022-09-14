#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int count[10];

    int pseudoPalindromicPaths(TreeNode *root) {
        int result = 0;
        if (!root) return result;
        count[root->val]++;
        if (!root->left && !root->right) {
            int cnt = 0;
            for (int i: count) cnt += i % 2;
            result = cnt <= 1;
        } else result = pseudoPalindromicPaths(root->left) + pseudoPalindromicPaths(root->right);
        count[root->val]--;
        return result;
    }
};

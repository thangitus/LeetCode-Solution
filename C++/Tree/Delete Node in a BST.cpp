#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;


/**
 * https://leetcode.com/problems/delete-node-in-a-bst/
 * */

class Solution {
public:
    TreeNode *minElement(TreeNode *root) {
        if (root == nullptr)return nullptr;
        TreeNode *temp = root;
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            TreeNode *nx = minElement(root->right);
            root->val = nx->val;
            root->right = deleteNode(root->right, nx->val);
            return root;
        }
        return root;
    }
};

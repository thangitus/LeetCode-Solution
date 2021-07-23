package dfs

import tree.TreeNode

/**
 * https://leetcode.com/problems/binary-tree-pruning/
 * */

fun pruneTree(root: TreeNode?): TreeNode? {
    if (root == null) return root
    root.left = pruneTree(root.left)
    root.right = pruneTree(root.right)
    return if (root.`val` == 1 || root.left != null || root.right != null) root
    else null
}
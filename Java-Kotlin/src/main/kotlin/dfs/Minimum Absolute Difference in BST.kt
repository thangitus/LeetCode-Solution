package dfs

import tree.TreeNode

/**
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 * */

var min = Int.MAX_VALUE
private var prev = -1
fun getMinimumDifference(root: TreeNode?): Int {
    if (root == null) return min
    getMinimumDifference(root.left)
    if (prev >= 0)
        min = Math.min(min, root.`val` - prev)
    prev = root.`val`
    getMinimumDifference(root.right)
    return min
}
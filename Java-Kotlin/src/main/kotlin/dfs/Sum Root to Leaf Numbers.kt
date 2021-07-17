package dfs

import tree.TreeNode

/**
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * */

var ans = 0
fun sumNumbers(root: TreeNode?): Int {
    dfs(root, 0)
    return ans
}

private fun dfs(root: TreeNode?, currSum: Int) {
    if (root == null) return
    val value = currSum * 10 + root.`val`
    if (root.left == null && root.right == null) ans += value
    if (root.left != null) dfs(root.left, value)
    if (root.right != null) dfs(root.right, value)
}
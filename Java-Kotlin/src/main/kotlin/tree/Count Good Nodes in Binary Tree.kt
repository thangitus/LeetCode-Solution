package tree

/**
 * https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 * */
fun goodNodes(root: TreeNode?): Int {
    return dfs(root, Int.MIN_VALUE)
}

private fun dfs(root: TreeNode?, max: Int): Int {
    if (root == null) return 0
    var ans = if (root.`val` >= max) 1 else 0
    val left = dfs(root.left, maxOf(max, root.`val`))
    val right = dfs(root.right, maxOf(max, root.`val`))
    ans += left + right
    return ans
}

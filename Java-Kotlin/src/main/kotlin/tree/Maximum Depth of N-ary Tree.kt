package tree

/**
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
 * */
fun maxDepth(root: Node?): Int {
    var ans = 0
    if (root == null) return ans
    root.children.forEach { ans = Math.max(ans, maxDepth(it)) }
    return ans + 1
}

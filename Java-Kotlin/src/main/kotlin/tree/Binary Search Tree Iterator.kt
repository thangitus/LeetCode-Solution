package tree

import java.util.*

/**
 * https://leetcode.com/problems/binary-search-tree-iterator/
 */

class BSTIterator(root: TreeNode?) {
    private val stack = Stack<TreeNode>()

    init {
        push(root)
    }

    private fun push(root: TreeNode?) {
        var node = root
        while (node != null) {
            stack.push(node)
            node = node.left
        }
    }

    fun next(): Int {
        val cur = stack.pop()
        push(cur.right)
        return cur.`val`
    }

    fun hasNext() = !stack.empty()

}

package bfs

import tree.TreeNode
import java.util.*


/**
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/
 * */

fun largestValues(root: TreeNode?): List<Int> {
    val ans = LinkedList<Int>()
    if (root == null) return ans
    val queue: Queue<TreeNode> = LinkedList()
    queue.add(root)
    while (!queue.isEmpty()) {
        var max = Int.MIN_VALUE
        for (i in queue.size downTo 1) {
            val front = queue.poll()
            max = Math.max(max, front.`val`)
            if (front.left != null) queue.add(front.left)
            if (front.right != null) queue.add(front.right)
        }
        ans.add(max)
    }
    return ans
}
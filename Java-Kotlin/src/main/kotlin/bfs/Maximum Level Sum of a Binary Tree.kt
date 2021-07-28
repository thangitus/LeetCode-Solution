package bfs

import tree.TreeNode
import java.util.*


/**
 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
 * */

fun maxLevelSum(root: TreeNode?): Int {
    var maxSum = root!!.`val`
    var ans = 1
    var level = 0
    val queue: Queue<TreeNode> = LinkedList()
    queue.add(root)
    while (!queue.isEmpty()) {
        var sumByLevel = 0
        for (i in queue.size downTo 1) {
            val curr = queue.poll()
            sumByLevel += curr.`val`
            if (curr.left != null) queue.add(curr.left)
            if (curr.right != null) queue.add(curr.right)
        }
        level++
        if (sumByLevel > maxSum) {
            maxSum = sumByLevel
            ans = level
        }
    }
    return ans
}
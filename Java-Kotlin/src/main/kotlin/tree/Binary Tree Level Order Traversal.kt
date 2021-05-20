package tree

import java.util.*
import kotlin.collections.ArrayList

fun levelOrder(root: TreeNode?): List<List<Int>> {
    val ans = ArrayList<ArrayList<Int>>()
    val queue: Queue<TreeNode> = LinkedList()
    queue.add(root)
    while (!queue.isEmpty()) {
        val row = ArrayList<Int>()
        for (i in queue.size downTo 1) {
            val front = queue.poll()
            if (front != null) {
                row.add(front.`val`)
                queue.add(front.left)
                queue.add(front.right)
            }
        }
        if (row.size > 0) ans.add(row)
    }
    return ans
}

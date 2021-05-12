package tree

import java.util.*

fun rightSideView(root: TreeNode?): List<Int> {
    val ans = mutableListOf<Int>()
    if (root == null) return ans
    val queue: Queue<TreeNode> = LinkedList()
    queue.add(root)
    while (!queue.isEmpty()) {
        var front = queue.peek()
        ans.add(front.`val`)
        val size = queue.size
        for (i in size downTo 1) {
            front = queue.peek();
            if (front.right != null) queue.add(front.right);
            if (front.left != null) queue.add(front.left);
            queue.poll()
        }
    }
    return ans
}

fun main() {
    val treeNode = TreeNode(1)
    treeNode.left = TreeNode(2)
    treeNode.right = TreeNode(3)
    print(rightSideView(treeNode))
}
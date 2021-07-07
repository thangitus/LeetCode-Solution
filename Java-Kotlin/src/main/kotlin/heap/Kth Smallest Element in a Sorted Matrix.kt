package heap

import java.util.*


/**
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * */

fun kthSmallest(matrix: Array<IntArray>, k: Int): Int {
    val minHeap = PriorityQueue<Cell>()
    for (i in matrix.indices)
        minHeap.add(Cell(0, i, matrix[0][i]))
    for (i in 0 until k) {
        val min = minHeap.poll()
        val x = min.x
        val y = min.y
        if (x == matrix.size - 1) continue
        minHeap.add(Cell(x + 1, y, matrix[x + 1][y]))
    }
    return minHeap.poll().num
}

class Cell(var x: Int, var y: Int, var num: Int) : Comparable<Cell> {
    override operator fun compareTo(other: Cell): Int {
        return num - other.num
    }
}


package dijkstra

import java.util.*


/**
 * https://leetcode.com/problems/swim-in-rising-water/
 * */

private val dir = arrayOf(intArrayOf(0, 1), intArrayOf(0, -1), intArrayOf(1, 0), intArrayOf(-1, 0))

fun swimInWater(grid: Array<IntArray>): Int {
    val pq = PriorityQueue { a: IntArray, b: IntArray ->
        grid[a[0]][a[1]] - grid[b[0]][b[1]]
    }
    pq.add(intArrayOf(0, 0))
    var level = 0
    val n: Int = grid.size
    val isVisited = Array(n) { BooleanArray(n) }

    while (!pq.isEmpty()) {
        val top: IntArray = pq.poll()
        level = Math.max(level, grid[top[0]][top[1]])
        if (top[0] == n - 1 && top[1] == n - 1)
            break

        for (next in dir) {
            val x = top[0] + next[0]
            val y = top[1] + next[1]
            if (!(x < 0 || x > n - 1 || y < 0 || y > n - 1) && !isVisited[x][y]) {
                isVisited[top[0]][top[1]] = true
                pq.add(intArrayOf(x, y))
            }
        }
    }
    return level
}

package bfs

import java.util.*

/**
 * https://leetcode.com/problems/01-matrix/
 * */

private val dir = arrayOf(arrayOf(0, -1), arrayOf(0, 1), arrayOf(-1, 0), arrayOf(1, 0))
fun updateMatrix(mat: Array<IntArray>): Array<IntArray> {
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    val ans = Array(mat.size) { IntArray(mat[0].size) }
    for (i in mat.indices)
        for (j in mat[i].indices)
            if (mat[i][j] == 0) queue.add(Pair(i, j))
    while (!queue.isEmpty()) {
        val curr = queue.poll()
        for (i in dir.indices) {
            val x = curr.first + dir[i][0]
            val y = curr.second + dir[i][1]
            if (x < 0 || x >= mat.size || y < 0 || y >= mat[0].size) continue
            if (mat[x][y] == 1 && ans[x][y] == 0) {
                ans[x][y] = ans[curr.first][curr.second] + 1
                queue.add(Pair(x, y))
            }
        }
    }
    return ans
}
package array

/**
 * https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 * */

data class Row(val index: Int, val solider: Int)

fun kWeakestRows(mat: Array<IntArray>, k: Int): IntArray {
    val rows = ArrayList<Row>()
    for (i in mat.indices) {
        var count = 0
        for (j in mat[i].indices) {
            if (mat[i][j] == 0) break
            count++
        }
        rows.add(Row(i, count))
    }
    rows.sortWith(compareBy({ it.solider }, { it.index }))
    val ans = IntArray(k)
    for (i in 0 until k) ans[i] = rows[i].index
    return ans
}

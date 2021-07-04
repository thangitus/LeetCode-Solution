package matrix

import java.util.*


/**
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
 * */

fun maxSumSubmatrix(matrix: Array<IntArray>, k: Int): Int {
    var ans = Int.MIN_VALUE
    for (r1 in matrix.indices) {
        val sumRow = IntArray(matrix[r1].size)
        for (r2 in r1 until matrix.size) {
            for (j in matrix[r2].indices) sumRow[j] += matrix[r2][j]
            ans = Math.max(ans, maxSumArray(sumRow, k))
        }
    }
    return ans
}

private fun maxSumArray(nums: IntArray, k: Int): Int {
    val bst = TreeSet<Int>()
    bst.add(0)
    var ans = Int.MIN_VALUE
    var sum = 0
    nums.forEach {
        sum += it
        val left = bst.ceiling(sum - k) // sum - left <= k -> left >= sum - k
        if (left != null) {
            ans = Math.max(ans, sum - left)
        }
        bst.add(sum)
    }
    return ans
}

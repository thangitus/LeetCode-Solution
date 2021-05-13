package greedy

import java.util.*

/**
 * https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
 * */

fun largestSumAfterKNegations(A: IntArray, K: Int): Int {
    A.sort()
    for (i in 0 until K) {
        A[0] *= -1
        A.sort()
    }
    return A.sum()
}
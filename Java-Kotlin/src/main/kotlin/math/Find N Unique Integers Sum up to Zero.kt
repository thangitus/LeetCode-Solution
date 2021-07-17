package math

/**
 * https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
 * */

fun sumZero(n: Int): IntArray {
    val ans = IntArray(n)
    var i = 0
    if (n and 1 != 0)
        ans[i++] = 0
    var value = 1
    while (i < n) {
        ans[i++] = value
        ans[i++] = -value
        value++
    }
    return ans
}
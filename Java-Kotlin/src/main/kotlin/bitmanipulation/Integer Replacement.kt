package bitmanipulation

/**
 * https://leetcode.com/problems/integer-replacement/
 * */

fun integerReplacement(n: Int): Int {
    return when {
        n == 1 -> 0
        n == Int.MAX_VALUE -> 32
        n and 1 == 0 -> 1 + integerReplacement(n shr 1)
        n == 3 || Integer.bitCount(n + 1) > Integer.bitCount(n - 1) -> 1 + integerReplacement(n - 1)
        else -> 1 + integerReplacement(n + 1)
    }
}

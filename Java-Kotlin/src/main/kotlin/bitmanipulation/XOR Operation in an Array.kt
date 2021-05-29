package bitmanipulation


/**
 * https://leetcode.com/problems/xor-operation-in-an-array/
 * */

fun xorOperation(n: Int, start: Int): Int {
    var ans = 0
    var value: Int
    for (i in 0 until n) {
        value = start + 2 * i
        ans = ans xor value
    }
    return ans
}

package bitmanipulation


/**
 * https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
 * */

fun numSteps(s: String): Int {
    var res = 0
    var carry = 0
    for (i in s.length - 1 downTo 1) {
        res++
        if (s[i] - '0' + carry == 1) {
            carry = 1
            res++
        }
    }
    return res + carry
}

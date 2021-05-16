package math

/**
 * https://leetcode.com/problems/perfect-number/
 * */

fun checkPerfectNumber(num: Int): Boolean {
    var ans = 0
    var i = 2
    while (i * i < num) {
        if (num % i == 0)
            ans += i + num / i
        i++
    }
    return ans == num - 1 && num > 1
}

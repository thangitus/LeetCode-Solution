package math

/**
 * https://leetcode.com/problems/self-dividing-numbers/
 * */

fun selfDividingNumbers(left: Int, right: Int): List<Int> {
    val ans = ArrayList<Int>()
    for (i in left..right)
        if (isSelfDividing(i))
            ans.add(i)
    return ans
}

private fun isSelfDividing(a: Int): Boolean {
    var number = a
    while (number != 0) {
        val digit = number % 10
        if (digit == 0 || a % digit != 0) return false
        number /= 10
    }
    return true
}

package array

import java.util.*

/**
 * https://leetcode.com/problems/add-to-array-form-of-integer/
 * */

fun addToArrayForm(digits: IntArray, k: Int): List<Int> {
    val ans = LinkedList<Int>()
    var value = k
    var remain = 0
    var i = digits.size - 1
    while (i >= 0 || value != 0) {
        var sum = (value % 10) + remain
        if (i >= 0) sum += digits[i]
        ans.add(sum % 10)
        remain = sum / 10
        value /= 10
        i--
    }
    if (remain != 0) ans.add(remain)
    return ans.reversed()
}

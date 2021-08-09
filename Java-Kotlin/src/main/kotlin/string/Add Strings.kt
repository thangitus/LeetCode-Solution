package string

/**
 * https://leetcode.com/problems/add-strings/
 * */

fun addStrings(num1: String, num2: String): String {
    var i: Int = num1.length - 1
    var j: Int = num2.length - 1

    val sb = StringBuilder()
    var carry = 0
    while (i >= 0 || j >= 0 || carry > 0) {
        var sum = carry
        if (i >= 0) sum += num1[i--] - '0'
        if (j >= 0) sum += num2[j--] - '0'
        val num = sum % 10
        carry = sum / 10
        sb.append(num)
    }
    return sb.reverse().toString()
}
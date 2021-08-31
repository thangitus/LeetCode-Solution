package string

/**
 * https://leetcode.com/problems/maximum-number-of-balloons/
 * */

fun maxNumberOfBalloons(text: String): Int {
    val count = IntArray(26)
    text.forEach { count[it - 'a']++ }
    count['l' - 'a'] /= 2
    count['o' - 'a'] /= 2
    val str = "balloon"
    var result = Int.MAX_VALUE
    str.forEach { result = Math.min(count[it - 'a'], result) }
    return result
}

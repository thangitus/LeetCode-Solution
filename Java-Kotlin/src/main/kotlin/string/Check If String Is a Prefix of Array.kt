package string

import java.lang.StringBuilder

/**
 * https://leetcode.com/problems/check-if-string-is-a-prefix-of-array
 * */

fun isPrefixString(s: String, words: Array<String>): Boolean {
    if (s.isEmpty()) return true
    val string = StringBuilder()
    for (i in words.indices) {
        string.append(words[i])
        if (string.length > s.length) return false
        if (string.toString() == s) return true
    }
    return false
}

package string

import java.lang.StringBuilder

/**
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * */

fun reverseWords(s: String): String {
    val strings = s.split(' ')
    val stringBuilder = StringBuilder()
    for (i in strings.indices) {
        stringBuilder.append(strings[i].reversed())
        if (i < strings.size - 1) stringBuilder.append(' ')
    }
    return stringBuilder.toString()
}
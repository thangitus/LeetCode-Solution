package string

/**
 * https://leetcode.com/problems/number-of-segments-in-a-string/
 * */

fun countSegments(s: String) =
    s.split(' ').filter { it.isNotEmpty() }.size
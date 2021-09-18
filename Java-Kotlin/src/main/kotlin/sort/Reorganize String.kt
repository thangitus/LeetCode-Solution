package sort

import java.lang.StringBuilder
import java.util.*
import kotlin.math.max

/**
 * https://leetcode.com/problems/reorganize-string/
 * */

fun reorganizeString(s: String): String {
    val count = IntArray(26)
    var maxCount = 0
    s.forEach { maxCount = max(maxCount, ++count[it - 'a']) }
    if (maxCount > (s.length + 1) / 2) return ""
    val maxHeap = PriorityQueue { c1: Char, c2: Char -> count[c2 - 'a'] - count[c1 - 'a'] }
    for (c in 'a'..'z') maxHeap.add(c)
    var i = 0
    val result = StringBuilder(s)
    var looped = false
    while (i < s.length) {
        val letter = maxHeap.poll()
        repeat(count[letter - 'a']) {
            result[i] = letter
            i += 2
            if (i >= s.length && !looped) {
                i = 1
                looped = true
            }
        }
    }
    return result.toString()
}

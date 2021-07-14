package sort

import java.lang.StringBuilder

/**
 * https://leetcode.com/problems/custom-sort-string/
 * */

fun customSortString(order: String, str: String): String {
    val rank = IntArray(26) { Int.MAX_VALUE }
    for (i in order.indices)
        rank[order[i] - 'a'] = i
    val array = str.toCharArray().sortedWith(compareBy { rank[it - 'a'] })
    val ans = StringBuilder()
    array.forEach { ans.append(it) }
    return ans.toString()
}
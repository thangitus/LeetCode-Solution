package string

import java.lang.StringBuilder

/**
 * https://leetcode.com/problems/find-and-replace-pattern/
 * */

fun findAndReplacePattern(words: Array<String>, pattern: String): List<String> {
    val pattern = value(pattern)
    val ans = ArrayList<String>()
    words.forEach {
        if (value(it) == pattern)
            ans.add(it)
    }
    return ans
}

private fun value(word: String): String {
    val map = HashMap<Char, Int>()
    for (c in word)
        if (!map.containsKey(c))
            map[c] = map.size

    val ans = StringBuilder()
    for (c in word) ans.append('a' + map[c]!!)
    return ans.toString()
}

package hashmap


/**
 * https://leetcode.com/problems/isomorphic-strings/
 * */

fun isIsomorphic(s: String, t: String): Boolean {
    val map = IntArray(512)
    for (i in s.indices) {
        val si = s[i].toInt()
        val ti = t[i].toInt() + 256
        if (map[si] != map[ti])
            return false
        map[si] = i + 1
        map[ti] = map[si]
    }
    return true
}
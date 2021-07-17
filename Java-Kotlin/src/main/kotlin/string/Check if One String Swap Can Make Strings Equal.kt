package string


/**
 * https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
 */

fun areAlmostEqual(s1: String, s2: String): Boolean {
    if (s1.length != s2.length) return false
    var diff = 0
    val pos = ArrayList<Int>()
    for (i in s1.indices)
        if (s1[i] != s2[i]) {
            diff++
            pos.add(i)
        }
    if (diff != 2 && diff != 0) return false
    if (diff == 0) return true
    return s1[pos[0]] == s2[pos[1]] && s1[pos[1]] == s2[pos[0]]
}
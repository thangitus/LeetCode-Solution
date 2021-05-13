package string

/**
 * https://leetcode.com/problems/check-if-the-sentence-is-pangram/
 * */

fun checkIfPangram(sentence: String): Boolean {
    if (sentence.length < 26) return false
    val flags = BooleanArray(26) { false }
    var cnt = 0
    for (c in sentence) {
        if (!flags[c - 'a']) cnt++
        flags[c - 'a'] = true
    }
    return cnt == 26
}

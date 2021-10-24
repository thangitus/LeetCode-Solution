package string

/**
 * https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
 * */

class Solution {
    fun countValidWords(sentence: String): Int {
        val tokens = sentence.split(' ')
        var result = 0
        tokens.forEach {
            if (valid(it))
                result++
        }
        return result
    }

    private fun valid(s: String): Boolean {
        if (s.isEmpty()) return false
        if (s == "!") return true
        s.forEach { if (it.isDigit()) return false }

        val len = s.length
        var mark = 0
        var hyphen = 0
        for (i in s.indices) {
            if (s[i] == '.' || s[i] == '!') mark++
            if (s[i] == '-') {
                hyphen++
                if (len < 3 || i == 0 || i == len - 1) return false
                if (!s[i - 1].isLetter() || !s[i + 1].isLetter()) return false
            }
            if ((s[i] == '!' || s[i] == ',' || s[i] == '.') && i != len - 1) return false
        }
        return mark < 2 && hyphen < 2
    }
}

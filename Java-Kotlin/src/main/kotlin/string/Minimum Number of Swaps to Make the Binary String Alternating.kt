package string

/**
 * https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
 * */

fun minSwaps(s: String): Int {
    var cntOne = 0
    var cntZero = 0
    s.forEach { if (it == '0') ++cntZero else ++cntOne }
    if (Math.abs(cntOne - cntZero) > 1) // Invalid
        return -1
    var missOne = 0
    var missZero = 0
    for (i in s.indices step 2) {
        if (s[i] != '0') missZero++
        else missOne++
    }
    return when {
        cntOne == cntZero -> Math.min(missOne, missZero)
        cntOne > cntZero -> missOne
        else -> missZero
    }
}

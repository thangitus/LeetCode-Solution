package bitmanipulation

/**
 * https://leetcode.com/problems/maximum-product-of-word-lengths/
 * */

fun maxProduct(words: Array<String>): Int {
    val value = IntArray(words.size)
    for (i in words.indices) {
        words[i].forEach {
            value[i] = value[i] or (1 shl (it - 'a'))
        }
    }
    var ans = 0
    for (i in words.indices)
        for (j in i + 1 until words.size)
            if ((value[i] and value[j] == 0))
                ans = Math.max(ans, words[i].length * words[j].length)
    return ans
}

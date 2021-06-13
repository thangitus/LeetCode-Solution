package hashmap


/**
 * https://leetcode.com/problems/palindrome-pairs/
 * */

fun palindromePairs(words: Array<String>): List<List<Int>> {
    val res: MutableList<List<Int>> = ArrayList()
    val map = HashMap<String, Int>()
    for (i in words.indices)
        map[words[i]] = i

    for (i in words.indices) {
        val cur = words[i]
        val reversed = cur.reversed()
        if (map.containsKey(reversed) && map[reversed] != i)
            res.add(listOf(i, map[reversed]!!))
        if (isPalindrome(cur, 0, cur.length - 1) && cur.isNotEmpty() && map.containsKey("")) {
            res.add(listOf(i, map[""]!!))
            res.add(listOf(map[""]!!, i))
        }
        for (len in 1 until cur.length) {
            if (isPalindrome(cur, 0, len - 1)) {
                val rightSide = cur.subSequence(len, cur.length).reversed().toString()
                if (map.containsKey(rightSide))
                    res.add(listOf(map[rightSide]!!, i))
            }
            if (isPalindrome(cur, len, cur.length - 1)) {
                val leftSide = cur.subSequence(0, len).reversed().toString()
                if (map.containsKey(leftSide))
                    res.add(listOf(i, map[leftSide]!!))
            }
        }
    }
    return res
}

private fun isPalindrome(s: String, left: Int, right: Int): Boolean {
    var i = left
    var j = right
    while (i <= j)
        if (s[i++] != s[j--]) return false
    return true
}

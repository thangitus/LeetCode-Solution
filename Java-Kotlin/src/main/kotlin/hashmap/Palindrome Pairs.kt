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

        // If contains reversed string of cur, then cur + cur.reversed() is palindrome.
        val reversed = cur.reversed()
        if (map.containsKey(reversed) && map[reversed] != i)
            res.add(listOf(i, map[reversed]!!))

        // If curr is a palindrome string, then cur + "" and "" + cur are palindrome
        if (isPalindrome(cur, 0, cur.length - 1) && cur.isNotEmpty() && map.containsKey("")) {
            res.add(listOf(i, map[""]!!))
            res.add(listOf(map[""]!!, i))
        }

        for (len in 1 until cur.length) {
            // If cur[0:len] is palindrome and there exists s2 is the reversing string of s1[len+1:] , then s2 + cur is palindrome
            if (isPalindrome(cur, 0, len - 1)) {
                val rightSide = cur.subSequence(len, cur.length).reversed().toString()
                if (map.containsKey(rightSide))
                    res.add(listOf(map[rightSide]!!, i))
            }

            // If cur[len+1:] is palindrome and there exists s2 is the reversing string of s1[0:len] , then cur + s2 is palindrome.
            if (isPalindrome(cur, len, cur.length - 1)) {
                val leftSide = cur.subSequence(0, len).reversed().toString()
                if (map.containsKey(leftSide))
                    res.add(listOf(i, map[leftSide]!!))
            }
        }
    }
    return res
}

private fun isPalindrome(s: String, start: Int, right: Int): Boolean {
    var i = start
    var j = right
    while (i <= j)
        if (s[i++] != s[j--]) return false
    return true
}

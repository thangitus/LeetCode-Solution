package twopointers

import java.util.HashSet

/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * */

fun lengthOfLongestSubstring(s: String): Int {
    var ans = 0
    var left = 0
    val set = HashSet<Char>()
    for (right in s.indices) {
        while (set.contains(s[right]))
            set.remove(s[left++])
        ans = Math.max(ans, right - left + 1)
        set.add(s[right])
    }
    return ans
}

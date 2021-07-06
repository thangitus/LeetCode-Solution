package hashmap


/**
 * https://leetcode.com/problems/longest-harmonious-subsequence/
 * */

fun findLHS(nums: IntArray): Int {
    val map = HashMap<Int, Int>()
    nums.forEach { map[it] = map.getOrDefault(it, 0) + 1 }
    var ans = 0
    map.keys.forEach {
        val value = Math.max(map.getOrDefault(it - 1, 0), map.getOrDefault(it + 1, 0))
        if (value != 0)
            ans = Math.max(ans, map[it]!! + value)
    }
    return ans
}

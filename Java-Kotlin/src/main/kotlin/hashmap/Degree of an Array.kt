package hashmap


/**
 * https://leetcode.com/problems/degree-of-an-array/
 * */

fun findShortestSubArray(nums: IntArray): Int {
    val counts = HashMap<Int, Int>()
    val first = HashMap<Int, Int>()
    var degree = 0
    var ans = Int.MAX_VALUE
    for (right in nums.indices) {
        val key = nums[right]
        first.putIfAbsent(key, right)
        counts[key] = counts.getOrDefault(key, 0) + 1
        val count = counts[key]!!
        val left = first[key]!!
        if (count > degree) {
            degree = count
            ans = right - left + 1
        } else if (count == degree)
            ans = Math.min(ans, right - left + 1)
    }
    return ans
}
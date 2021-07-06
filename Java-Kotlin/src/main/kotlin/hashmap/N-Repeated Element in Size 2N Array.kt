package hashmap


/**
 * https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
 * */

fun repeatedNTimes(nums: IntArray): Int {
    val n = nums.size / 2
    val map = HashMap<Int, Int>()
    nums.forEach {
        map[it] = map.getOrDefault(it, 0) + 1
        if (map[it] == n) return it
    }
    return 0
}
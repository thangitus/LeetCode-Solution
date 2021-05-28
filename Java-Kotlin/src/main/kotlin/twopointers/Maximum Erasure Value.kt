package twopointers

import java.util.HashSet

/**
 * https://leetcode.com/problems/maximum-erasure-value/
 * */

fun maximumUniqueSubarray(nums: IntArray): Int {
    var ans = 0
    var sum = 0
    var left = 0
    val set = HashSet<Int>()
    nums.forEach {
        while (set.contains(it)) {
            set.remove(nums[left])
            sum -= nums[left++]
        }
        sum += it
        set.add(it)
        ans = Math.max(ans, sum)
    }
    return ans
}

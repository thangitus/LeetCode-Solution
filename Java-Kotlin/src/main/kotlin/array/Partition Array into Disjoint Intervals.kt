package array

/**
 * https://leetcode.com/problems/partition-array-into-disjoint-intervals/
 * */

fun partitionDisjoint(nums: IntArray): Int {
    var localMax = nums[0]
    var partitionIdx = 0
    var max = localMax
    for (i in 1 until nums.size)
        if (localMax > nums[i]) {
            localMax = max
            partitionIdx = i
        } else max = Math.max(max, nums[i])
    return partitionIdx + 1
}
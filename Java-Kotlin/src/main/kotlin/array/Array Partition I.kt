package array

/**
 * https://leetcode.com/problems/array-partition-i/
 * */

fun arrayPairSum(nums: IntArray): Int {
    var sum = 0
    nums.sort()
    for (i in nums.indices step 2)
        sum += nums[i]
    return sum
}
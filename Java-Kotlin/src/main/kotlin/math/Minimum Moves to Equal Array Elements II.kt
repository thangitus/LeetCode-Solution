package math

/**
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 * */

fun minMoves2(nums: IntArray): Int {
    nums.sort()
    var ans = 0
    var median = nums[nums.size / 2]
    for (num in nums)
        ans += Math.abs(num - median)
    return ans
}

package dfs

/**
 * https://leetcode.com/problems/matchsticks-to-square/
 * */

fun makesquare(nums: IntArray): Boolean {
    if (nums.size < 4) return false
    var sum = 0
    for (num in nums) sum += num
    return if (sum % 4 != 0) false
    else dfs(nums, IntArray(4), 0, sum / 4)
}

private fun dfs(nums: IntArray, sums: IntArray, index: Int, target: Int): Boolean {
    if (index == nums.size)
        return sums[0] == target && sums[1] == target && sums[2] == target

    for (i in 0..3) {
        if (sums[i] + nums[index] > target) continue
        sums[i] += nums[index]
        if (dfs(nums, sums, index + 1, target)) return true
        sums[i] -= nums[index]
    }
    return false
}

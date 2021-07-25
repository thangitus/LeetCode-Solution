package prefix_sum

/**
 * https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
 * */

fun minStartValue(nums: IntArray): Int {
    var min = nums[0]
    for (i in 1 until nums.size) {
        nums[i] += nums[i - 1]
        min = Math.min(min, nums[i])
    }
    val ans = 1 - min
    if (ans < 1) return 1
    return ans
}
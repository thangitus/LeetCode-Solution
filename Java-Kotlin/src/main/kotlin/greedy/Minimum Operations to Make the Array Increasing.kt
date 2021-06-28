package greedy

/**
 * https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
 * */

fun minOperations(nums: IntArray): Int {
    val cloned = nums.clone()
    for (i in 1 until cloned.size)
        cloned[i] = Math.max(cloned[i - 1] + 1, cloned[i])
    return cloned.sum() - nums.sum()
}

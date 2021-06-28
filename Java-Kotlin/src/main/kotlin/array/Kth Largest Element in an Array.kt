package array

/**
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 * */

fun findKthLargest(nums: IntArray, k: Int): Int {
    nums.sort()
    return nums[nums.size - k - 1]
}

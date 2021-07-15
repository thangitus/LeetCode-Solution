package twopointers

/**
 * https://leetcode.com/problems/valid-triangle-number/
 * */

fun triangleNumber(nums: IntArray): Int {
    nums.sort()
    var count = 0
    for (i in nums.size - 1 downTo 2) {
        var left = 0
        var right = i - 1
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                count += right - left
                right--
            } else left++
        }
    }
    return count
}
package sort

/**
 * https://leetcode.com/problems/3sum-closest/
 * */

fun threeSumClosest(nums: IntArray, target: Int): Int {
    nums.sort()
    var res = nums[0] + nums[1] + nums[2]
    for (i in 0..nums.size - 2) {
        var left = i + 1
        var right = nums.size - 1
        while (left < right) {
            val sum = nums[i] + nums[left] + nums[right]
            if (sum == target) return target
            if (Math.abs(target - sum) < Math.abs(target - res)) res = sum
            if (sum < target) left++
            else right--
        }
    }
    return res
}
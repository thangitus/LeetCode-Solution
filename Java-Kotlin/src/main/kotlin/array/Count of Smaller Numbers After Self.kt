package array

/**
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 * */

fun countSmaller(nums: IntArray): List<Int> {
    val ans = IntArray(nums.size)
    val sorted = ArrayList<Int>()
    for (i in nums.size - 1 downTo 0) {
        var index = binarySearch(sorted, nums[i])
        ans[i] = index
        sorted.add(index, nums[i])
    }
    return ans.toList()
}

// find the first position greater than or equal to target in sortedNums
private fun binarySearch(sorted: List<Int>, target: Int): Int {
    var left = 0
    var right = sorted.size
    while (left < right) {
        val mid = left + (right - left) / 2
        if (sorted[mid] < target) left = mid + 1
        else right = mid
    }
    return left
}
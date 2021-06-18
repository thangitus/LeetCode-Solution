package array

/**
 * https://leetcode.com/problems/range-sum-query-mutable/
 * */

class NumArray(val nums: IntArray) {
    private val sums = IntArray(nums.size + 1) { 0 }

    init {
        for (i in nums.indices)
            sums[i + 1] = nums[i] + sums[i]
    }

    fun update(index: Int, value: Int) {
        val diff = value - nums[index]
        nums[index] = value
        for (i in index + 1 until sums.size)
            sums[i] += diff
    }

    fun sumRange(left: Int, right: Int): Int {
        return sums[right + 1] - sums[left]
    }
}

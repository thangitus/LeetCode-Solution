package greedy

/**
 * https://leetcode.com/problems/candy/
 * */

fun candy(ratings: IntArray): Int {
    val nums = IntArray(ratings.size) { 1 }
    for (i in 1 until ratings.size)
        if (ratings[i] > ratings[i - 1])
            nums[i] = nums[i - 1] + 1

    for (i in ratings.size - 2 downTo 0)
        if (ratings[i] > ratings[i + 1])
            nums[i] = maxOf(nums[i + 1] + 1, nums[i])
    return nums.sum()
}

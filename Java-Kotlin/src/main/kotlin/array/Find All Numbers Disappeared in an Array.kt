package array


/**
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * */

fun findDisappearedNumbers(nums: IntArray): List<Int> {
    nums.forEach {
        if (nums[Math.abs(it) - 1] > 0)
            nums[Math.abs(it) - 1] *= -1
    }
    val ans = ArrayList<Int>()
    for (i in 1..nums.size)
        if (nums[i - 1] > 0) ans.add(i)
    return ans
}

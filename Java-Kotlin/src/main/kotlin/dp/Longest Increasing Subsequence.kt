package dp

/**
 * https://leetcode.com/problems/longest-increasing-subsequence/
 * */

/**
 * O(n*n) solution:
 *
 * ```kotlin
 *     fun lengthOfLIS(nums: IntArray): Int {
 *           val lis = IntArray(nums.size) { 1 }
 *           for (i in 1 until nums.size)
 *              for (j in 0 until i)
 *                  if (nums[i] > nums[j])
 *                      lis[i] = Math.max(lis[i], lis[j] + 1)
 *           return lis.max()!!
 *       }
 * ```
 */


fun lengthOfLIS(nums: IntArray): Int {
    val sub = ArrayList<Int>()
    sub.add(nums[0])
    for (i in 1 until nums.size) {
        if (nums[i] > sub.last())
            sub.add(nums[i])
        else if (nums[i] < sub.last()) {
            val index = binarySearchGreaterOrEqual(sub, nums[i])
            sub[index] = nums[i]
        }
    }

    return sub.size
}

private fun binarySearchGreaterOrEqual(nums: List<Int>, value: Int): Int {
    var left = 0
    var right = nums.size - 1
    var pos = right
    while (left < right) {
        val mid = (left + right).ushr(1) // safe from overflows
        val cmp = compareValues(nums[mid], value)

        when {
            cmp < 0 -> left = mid + 1
            else -> {
                pos = mid
                right = mid
            }
        }
    }
    return pos
}

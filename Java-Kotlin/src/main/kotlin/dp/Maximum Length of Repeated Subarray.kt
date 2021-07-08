package dp

/**
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/
 * */

fun findLength(nums1: IntArray, nums2: IntArray): Int {
    val dp = Array(nums1.size + 1) { IntArray(nums2.size + 1) }
    var ans = Int.MIN_VALUE
    for (i in nums1.indices)
        for (j in nums2.indices) {
            if (nums1[i] == nums2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1
            ans = Math.max(ans, dp[i + 1][j + 1])
        }
    return ans
}

package math

/**
 * https://leetcode.com/problems/rotate-function/

    nums = [4,3,2,6]

    F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
    F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
    F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
    F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

    F(k) = 0 * Ak[0] + 1 * Ak[1] + ... + (n-1) * Ak[n-1]
    F(k-1) = 0 * Ak-1[0] + 1 * Ak-1[1] + ... + (n-1) * Ak-1[n-1]
           = 0 * Ak[1] + 1 * Ak[2] + ... + (n-2) * Ak[n-1] + (n-1) * Ak[0]

    F(k) - F(k-1) = Ak[1] + Ak[2] + ... + Ak[n-1] + (1-n)Ak[0]
                  = (Ak[0] + ... + Ak[n-1]) - nAk[0]
                  = sum - nAk[0]

    => F(k) = F(k-1) + sum - nAk[0]

    What is Ak[0]?
    k = 0; Ak[0] = A[0];
    k = 1; Ak[0] = A[len-1];
    k = 2; Ak[0] = A[len-2];
 * */

fun maxRotateFunction(nums: IntArray): Int {
    var sum = 0
    var cur = 0
    for (i in nums.indices) {
        sum += nums[i]
        cur += i * nums[i]
    }
    var ans = cur
    for (i in nums.size - 1 downTo 1) {
        cur = cur + sum - nums.size * nums[i]
        ans = Math.max(ans, cur)
    }
    return ans
}

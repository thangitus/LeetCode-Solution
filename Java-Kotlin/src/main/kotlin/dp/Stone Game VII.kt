package dp

/**
 * https://leetcode.com/problems/stone-game-vii/
 * */

fun stoneGameVII(stones: IntArray): Int {
    val n = stones.size
    val sum = IntArray(n + 1)
    for (i in 0 until n) sum[i + 1] = sum[i] + stones[i]
    val dp = Array(n) { IntArray(n) }
    for (len in 2..n) {
        var i = 0
        while (i <= n - len) {
            val j = i + len - 1
            dp[i][j] = Math.max(sum[j + 1] - sum[i + 1] - dp[i + 1][j], sum[j] - sum[i] - dp[i][j - 1]);
            i++
        }
    }
    return dp[0][n - 1]
}

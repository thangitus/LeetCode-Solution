package dp

/**
 * https://leetcode.com/problems/stone-game/
 * */

class Solution {
    fun stoneGame(piles: IntArray): Boolean {
        val n = piles.size
        val dp = Array(n) { Array(n) { Pair(0, 0) } }
        for (left in n - 1 downTo 0)
            for (right in left until n) {
                if (left == right) {
                    dp[left][right] = Pair(piles[left], 0)
                    continue
                }
                val pickLeft = dp[left + 1][right]
                val pickRight = dp[left][right - 1]
                dp[left][right] = if (piles[left] + pickLeft.second > piles[right] + pickRight.second)
                    Pair(piles[left] + pickLeft.second, pickLeft.first)
                else Pair(piles[right] + pickRight.second, pickRight.first)
            }
        val alexScore = dp[0][n - 1].first
        val leeScore = dp[0][n - 1].second
        return alexScore > leeScore
    }
}

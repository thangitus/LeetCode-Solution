package dp

/**
 * https://leetcode.com/problems/interleaving-string/
 * */

fun isInterleave(s1: String, s2: String, s3: String): Boolean {
    if (s1.length + s2.length != s3.length) return false
    val dp = Array(s1.length + 1) { BooleanArray(s2.length + 1) }
    dp[0][0] = true
    for (i in 1 until dp.size)
        if (s1[i - 1] == s3[i - 1] && dp[i - 1][0]) dp[i][0] = true
    for (j in 1 until dp[0].size)
        if (s2[j - 1] == s3[j - 1] && dp[0][j - 1]) dp[0][j] = true
    for (i in 1 until dp.size)
        for (j in 1 until dp[0].size) {
            val k = i + j - 1
            if (s3[k] == s1[i - 1])
                dp[i][j] = dp[i - 1][j]
            if (s3[k] == s2[j - 1])
                dp[i][j] = dp[i][j] || dp[i][j - 1]
        }
    return dp[s1.length][s2.length]
}

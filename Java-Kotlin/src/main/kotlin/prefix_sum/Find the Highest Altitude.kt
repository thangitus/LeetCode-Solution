package prefix_sum

/**
 * https://leetcode.com/problems/find-the-highest-altitude/
 * */

fun largestAltitude(gain: IntArray): Int {
    var ans = 0
    var sum = 0
    for (i in gain.indices) {
        sum += gain[i]
        ans = Math.max(ans, sum)
    }
    return ans
}
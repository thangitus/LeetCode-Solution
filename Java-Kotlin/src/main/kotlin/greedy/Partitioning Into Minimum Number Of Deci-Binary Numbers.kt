package greedy

/**
 * https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * */

fun minPartitions(n: String): Int {
    var ans = 0
    n.forEach { ans = Math.max(ans, it - '0') }
    return ans
}

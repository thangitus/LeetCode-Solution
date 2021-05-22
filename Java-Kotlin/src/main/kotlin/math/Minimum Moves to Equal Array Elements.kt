package math

/**
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 * */

fun minMoves(nums: IntArray): Int {
    val min = nums.min()
    var ans = 0
    nums.forEach { ans += it - min!! }
    return ans
}

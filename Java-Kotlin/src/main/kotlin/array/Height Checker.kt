package array

/**
 * https://leetcode.com/problems/height-checker/
 * */

fun heightChecker(heights: IntArray): Int {
    val expected = heights.clone()
    expected.sort()
    var ans = 0
    for (i in expected.indices)
        if (expected[i] != heights[i]) ans++
    return ans
}

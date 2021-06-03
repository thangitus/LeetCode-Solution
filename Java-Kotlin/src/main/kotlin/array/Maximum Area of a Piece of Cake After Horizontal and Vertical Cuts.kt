package array

/**
 * https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
 * */

fun maxArea(h: Int, w: Int, horizontalCuts: IntArray, verticalCuts: IntArray): Int {
    horizontalCuts.sort()
    verticalCuts.sort()
    var hMax = Math.max(horizontalCuts[0] - 0, h - horizontalCuts[horizontalCuts.size - 1])
    var vMax = Math.max(verticalCuts[0] - 0, w - verticalCuts[verticalCuts.size - 1])
    for (i in 1 until horizontalCuts.size)
        hMax = Math.max(hMax, horizontalCuts[i] - horizontalCuts[i - 1])
    for (j in 1 until verticalCuts.size)
        vMax = Math.max(vMax, verticalCuts[j] - verticalCuts[j - 1])

    return (vMax.toLong() * hMax % 1000000007).toInt()
}

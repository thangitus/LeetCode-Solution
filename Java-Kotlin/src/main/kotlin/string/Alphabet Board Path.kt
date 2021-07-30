package string

import java.lang.StringBuilder

/**
 * https://leetcode.com/problems/alphabet-board-path/
 * */

fun alphabetBoardPath(target: String): String {
    val ans = StringBuilder()
    var last = Pair(0, 0)
    target.forEach {
        val x = (it - 'a') / 5
        val y = (it - 'a') % 5
        val pos = Pair(x, y)
        ans.append(getPath(last, pos))
        ans.append('!')
        last = pos
    }
    return ans.toString()
}

private fun getPath(from: Pair<Int, Int>, to: Pair<Int, Int>): String {
    var dx = from.first - to.first
    var dy = from.second - to.second
    val ans = StringBuilder()
    while (dx > 0) {
        ans.append("U")
        dx--
    }
    while (dy > 0) {
        ans.append("L")
        dy--
    }
    while (dx < 0) {
        ans.append("D")
        dx++
    }
    while (dy < 0) {
        ans.append("R")
        dy++
    }
    return ans.toString()
}

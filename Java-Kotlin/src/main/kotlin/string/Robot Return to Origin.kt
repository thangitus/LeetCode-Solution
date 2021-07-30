package string

/**
 * https://leetcode.com/problems/robot-return-to-origin/
 * */

fun judgeCircle(moves: String): Boolean {
    var x = 0
    var y = 0
    moves.forEach {
        when (it) {
            'L' -> x++
            'R' -> x--
            'U' -> y++
            'D' -> y--
        }
    }
    return x == 0 && y == 0
}

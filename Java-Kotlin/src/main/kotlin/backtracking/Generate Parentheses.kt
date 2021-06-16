package backtracking

import java.lang.StringBuilder
import java.util.ArrayList


/**
 * https://leetcode.com/problems/open-the-lock/
 * */

var total: Int = 0
private val res = ArrayList<String>()
fun generateParenthesis(n: Int): List<String> {
    total = n * 2
    backtracking(StringBuilder(), 0, 0)
    return res
}

private fun backtracking(cur: StringBuilder, open: Int, close: Int) {
    if (cur.length == total) {
        res.add(cur.toString())
        return
    }
    if (open < total / 2) {
        cur.append('(')
        backtracking(cur, open + 1, close)
        cur.deleteCharAt(cur.length - 1)
    }
    if (close < open) {
        cur.append(')')
        backtracking(cur, open, close + 1)
        cur.deleteCharAt(cur.length - 1)
    }
}

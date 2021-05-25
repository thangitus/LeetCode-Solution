package stack

import java.util.*

/**
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * */

fun evalRPN(tokens: Array<String>): Int {
    val stack = Stack<Int>()
    val operator = arrayOf("+", "-", "*", "/")
    tokens.forEach {
        if (it in operator) {
            val b = stack.pop()
            val a = stack.pop()
            val c = when (it) {
                "+" -> a + b
                "-" -> a - b
                "*" -> a * b
                "/" -> a / b
                else -> 0
            }
            stack.add(c)
        } else stack.add(it.toInt())
    }
    return stack.pop()
}

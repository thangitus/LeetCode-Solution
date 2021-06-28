package stack

import java.lang.StringBuilder
import java.util.*

/**
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 * */

fun removeDuplicates(s: String): String {
    val stack = Stack<Char>()
    val ans = StringBuilder()
    s.forEach {
        if (!stack.empty() && stack.peek() == it)
            stack.pop()
        else stack.push(it)
    }
    while (!stack.empty()) ans.append(stack.pop())
    return ans.reverse().toString();
}

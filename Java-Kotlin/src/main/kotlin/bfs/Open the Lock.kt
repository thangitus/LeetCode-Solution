package bfs

import java.util.*


/**
 * https://leetcode.com/problems/open-the-lock/
 * */

fun openLock(deadends: Array<String>, target: String): Int {
    var ans = 0
    val queue: Queue<String> = LinkedList()
    val dead = HashSet<String>()
    val visited = HashSet<String>()
    deadends.forEach { dead.add(it) }
    if (dead.contains(target) || dead.contains("0000")) return -1
    queue.add("0000")
    visited.add("0000")
    while (!queue.isEmpty()) {
        for (i in queue.size downTo 1) {
            val front = queue.poll()
            if (front == target) return ans
            val sb = StringBuilder(front)
            for (j in 0..3) {
                val c = sb[j] - '0'
                val s1 = sb.substring(0, j) + (if (c == 9) 0 else c + 1) + sb.substring(j + 1)
                val s2 = sb.substring(0, j) + (if (c == 0) 9 else c - 1) + sb.substring(j + 1)
                if (!visited.contains(s1) && !dead.contains(s1)) {
                    queue.add(s1)
                    visited.add(s1)
                }
                if (!visited.contains(s2) && !dead.contains(s2)) {
                    queue.add(s2)
                    visited.add(s2)
                }
            }
        }
        ans++;
    }
    return -1
}

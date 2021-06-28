package heap

import java.util.*
import kotlin.collections.ArrayList


/**
 * https://leetcode.com/problems/single-threaded-cpu/
 * */

class Task(val index: Int, val enqueueTime: Int, val processingTime: Int)

fun getOrder(t: Array<IntArray>): IntArray {
    val n = t.size
    val tasks = ArrayList<Task>()
    for (i in t.indices)
        tasks.add(Task(i, t[i][0], t[i][1]))
    tasks.sortBy { it.enqueueTime }
    val minHeap = PriorityQueue { task1: Task, task2: Task ->
        when {
            task1.processingTime != task2.processingTime -> task1.processingTime - task2.processingTime
            else -> task1.index - task2.index
        }
    }
    val ans = IntArray(n)
    var i = 0
    var j = 0
    var currTime = 0

    while (i < n) {
        while (j < n && tasks[j].enqueueTime >= currTime)
            minHeap.add(tasks[j++])
        if (minHeap.isEmpty()) {
            currTime = tasks[j].enqueueTime
            continue
        }
        val top = minHeap.poll()
        ans[i++] = top.index
        currTime += top.processingTime
    }
    return ans
}

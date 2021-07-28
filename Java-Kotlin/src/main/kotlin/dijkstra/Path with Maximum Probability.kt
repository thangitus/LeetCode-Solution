package dijkstra

import java.util.*


/**
 * https://leetcode.com/problems/path-with-maximum-probability/
 * */

fun maxProbability(n: Int, edges: Array<IntArray>, succProb: DoubleArray, start: Int, end: Int): Double {
    val graph = Array(n) { ArrayList<Pair<Int, Double>>() }
    for (i in edges.indices) {
        val edge = edges[i]
        graph[edge[0]].add(Pair(edge[1], succProb[i]))
        graph[edge[1]].add(Pair(edge[0], succProb[i]))
    }

    val pq = PriorityQueue { a: Pair<Int, Double>, b: Pair<Int, Double> ->
        if (a.second == b.second) return@PriorityQueue 0
        if (a.second > b.second) return@PriorityQueue -1
        return@PriorityQueue 1
    }
    val dist = DoubleArray(n) { 0.0 }
    dist[start] = 1.0
    pq.add(Pair(start, 1.0))
    while (!pq.isEmpty()) {
        val top = pq.poll()
        val u = top.first
        val w = top.second
        graph[u].forEach {
            if (w * it.second > dist[it.first]) {
                dist[it.first] = w * it.second
                pq.add(Pair(it.first, dist[it.first]))
            }
        }
    }
    return dist[end]
}
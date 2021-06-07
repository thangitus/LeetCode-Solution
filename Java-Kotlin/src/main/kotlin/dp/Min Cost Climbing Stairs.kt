package dp

/**
 * https://leetcode.com/problems/min-cost-climbing-stairs/
 * */

fun minCostClimbingStairs(cost: IntArray): Int {
    for (i in 2 until cost.size)
        cost[i] += Math.min(cost[i - 1], cost[i - 2])
    return Math.min(cost[cost.size - 1], cost[cost.size - 2])
}

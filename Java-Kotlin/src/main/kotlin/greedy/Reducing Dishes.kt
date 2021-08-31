package greedy

/**
 * https://leetcode.com/problems/reducing-dishes/
 * */

fun maxSatisfaction(satisfaction: IntArray): Int {
    satisfaction.sort()
    var sum = 0
    var result = 0
    for (i in satisfaction.size - 1 downTo 0) {
        sum += satisfaction[i]
        if (sum > 0) result += sum
        else break
    }
    return result;
}


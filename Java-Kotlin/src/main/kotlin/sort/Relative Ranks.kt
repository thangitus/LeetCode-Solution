package sort

/**
 * https://leetcode.com/problems/relative-ranks/
 * */

class Athlete(val index: Int, val score: Int)

fun findRelativeRanks(score: IntArray): Array<String> {
    val athletes = ArrayList<Athlete>()
    for (i in score.indices)
        athletes.add(Athlete(i, score[i]))
    athletes.sortByDescending { it.score }
    val ans = Array(score.size) { "" }
    for (i in athletes.indices) {
        ans[athletes[i].index] = when (i) {
            0 -> "Gold Medal"
            1 -> "Silver Medal"
            2 -> "Bronze Medal"
            else -> (i + 1).toString()
        }
    }
    return ans
}

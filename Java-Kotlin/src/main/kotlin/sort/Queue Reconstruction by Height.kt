package sort

/**
 * https://leetcode.com/problems/queue-reconstruction-by-height/
 * */

fun reconstructQueue(people: Array<IntArray>): Array<IntArray> {
    people.sortWith(compareBy<IntArray> { -it[0] }.thenBy { it[1] })
    val result = ArrayList<IntArray>()
    people.forEach {
        result.add(it[1], it)
    }
    return result.toArray(arrayOfNulls<IntArray>(people.size))
}

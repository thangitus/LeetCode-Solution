package hashmap


/**
 * https://leetcode.com/problems/reduce-array-size-to-the-half/
 * */

fun minSetSize(arr: IntArray): Int {
    val count = HashMap<Int, Int>()
    arr.forEach {
        count[it] = count.getOrDefault(it, 0) + 1
    }
    val sortedMap = count.values.sortedDescending()
    var sum = 0
    for (i in sortedMap.indices) {
        sum += sortedMap[i]
        if (sum >= arr.size / 2) return i + 1
    }
    return 1
}

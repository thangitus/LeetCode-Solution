package hashmap


/**
 * https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 * */

fun findRestaurant(list1: Array<String>, list2: Array<String>): Array<String> {
    val map = HashMap<String, Int>()
    for (i in list1.indices)
        map[list1[i]] = i
    val ans = ArrayList<String>()
    var minSum = Int.MAX_VALUE

    for (i in list2.indices) {
        if (map.containsKey(list2[i])) {
            val j = map[list2[i]]!!
            if (i + j < minSum) {
                minSum = i + j
                ans.clear()
                ans.add(list2[i])
            } else if (i + j == minSum) ans.add(list2[i])
        }
    }
    return ans.toTypedArray()
}
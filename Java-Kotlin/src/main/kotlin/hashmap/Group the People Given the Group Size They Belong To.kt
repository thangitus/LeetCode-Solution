package hashmap


/**
 * https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
 * */

fun groupThePeople(groupSizes: IntArray): List<List<Int>> {
    val map = HashMap<Int, ArrayList<Int>>()
    val result = ArrayList<List<Int>>()
    for (i in groupSizes.indices) {
        val group = map.getOrPut(groupSizes[i]) { ArrayList() }
        group.add(i)
        if (group.size == groupSizes[i]) {
            result.add(group)
            map[groupSizes[i]] = ArrayList()
        }
    }
    return result
}

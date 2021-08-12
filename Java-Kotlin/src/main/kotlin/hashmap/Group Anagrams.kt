package hashmap

import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap


/**
 * https://leetcode.com/problems/group-anagrams/
 * */

fun groupAnagrams(anagrams: Array<String>): List<List<String>> {
    val map = HashMap<String, LinkedList<String>>()
    anagrams.forEach {
        val key = it.toCharArray().sorted().toString()
        if (!map.contains(key)) map[key] = LinkedList()
        map[key]?.add(it)
    }
    return ArrayList(map.values)
}
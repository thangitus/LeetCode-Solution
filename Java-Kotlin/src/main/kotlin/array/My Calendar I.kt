package array

import java.util.*


/**
 * https://leetcode.com/problems/my-calendar-i/
 * */

class MyCalendar {
    private val map = TreeMap<Int, Int>()
    fun book(start: Int, end: Int): Boolean {
        val floor = map.floorEntry(start)
        val ceiling = map.ceilingEntry(start)
        if (floor != null && floor.value > start)
            return false
        if (ceiling != null && ceiling.key < end)
            return false
        map[start] = end
        return true
    }
}
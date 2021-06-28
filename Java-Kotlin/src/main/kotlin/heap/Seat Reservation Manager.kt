package heap

import java.util.*


/**
 * https://leetcode.com/problems/seat-reservation-manager/
 * */

class SeatManager(n: Int) {

    private val minHeap = PriorityQueue<Int>()

    init {
        for (i in 1..n) minHeap.add(i)
    }

    fun reserve() = minHeap.poll()!!

    fun unreserve(seatNumber: Int) = minHeap.add(seatNumber)

}

/**
 * Your SeatManager object will be instantiated and called as such:
 * var obj = SeatManager(n)
 * var param_1 = obj.reserve()
 * obj.unreserve(seatNumber)
 */
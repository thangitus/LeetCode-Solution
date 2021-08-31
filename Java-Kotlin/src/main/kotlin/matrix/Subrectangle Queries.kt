package matrix

import java.util.*


/**
 * https://leetcode.com/problems/subrectangle-queries/
 * */

class SubrectangleQueries(val rectangle: Array<IntArray>) {
    val queries = LinkedList<IntArray>()
    fun updateSubrectangle(row1: Int, col1: Int, row2: Int, col2: Int, newValue: Int) {
        queries.add(intArrayOf(row1, col1, row2, col2, newValue))
    }

    fun getValue(row: Int, col: Int): Int {
        for (i in queries.size - 1 downTo 0) {
            val query = queries[i]
            if (row >= query[0] && col >= query[1] && row <= query[2] && col <= query[3])
                return query[4]
        }
        return rectangle[row][col]
    }

}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * var obj = SubrectangleQueries(rectangle)
 * obj.updateSubrectangle(row1,col1,row2,col2,newValue)
 * var param_2 = obj.getValue(row,col)
 */
package tree

/**
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
 * https://www.youtube.com/watch?v=_mbnPPHJmTQ
 * */

fun isValidSerialization(preorder: String): Boolean {
    var available = 1
    val tokens = preorder.split(',')
    tokens.forEach {
        if (--available < 0) return false
        if (it != "#") available += 2
    }
    return available == 0
}

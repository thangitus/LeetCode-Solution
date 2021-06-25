package union

/**
 * https://leetcode.com/problems/redundant-connection/
 * */

lateinit var parents: IntArray
lateinit var ranks: IntArray
fun findRedundantConnection(edges: Array<IntArray>): IntArray {
    parents = IntArray(edges.size + 1) { it }
    ranks = IntArray(edges.size + 1) { 0 }
    var ans = IntArray(2)
    edges.forEach { if (!union(it[0], it[1])) ans = it }
    return ans
}

private fun findParent(u: Int): Int {
    if (u != parents[u])
        parents[u] = findParent(parents[u])
    return parents[u]
}

private fun union(u: Int, v: Int): Boolean {
    val up = findParent(u)
    val vp = findParent(v)
    if (up == vp) return false
    when {
        ranks[up] > ranks[vp] -> parents[vp] = up
        ranks[up] < ranks[vp] -> parents[up] = vp
        else -> {
            parents[up] = vp
            ranks[vp]++
        }
    }
    return true
}

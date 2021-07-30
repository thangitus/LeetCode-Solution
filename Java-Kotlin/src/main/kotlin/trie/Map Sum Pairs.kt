package trie

/**
 * https://leetcode.com/problems/map-sum-pairs/
 * */

class MapSum() {
    val root = Node()
    fun insert(key: String, value: Int) = root.addKey(key, value)

    fun sum(prefix: String) = root.sum(prefix)

    class Node {
        var value = 0
        private val child = HashMap<Char, Node>()

        fun addKey(key: String, value: Int) {
            var curr = this
            key.forEach {
                curr.child.putIfAbsent(it, Node())
                curr = curr.child[it]!!
            }
            curr.value = value
        }

        fun sum(prefix: String): Int {
            var curr = this
            prefix.forEach {
                if (!curr.child.containsKey(it)) return 0
                curr = curr.child[it]!!
            }
            return dfs(curr)
        }

        private fun dfs(node: Node): Int {
            var sum = 0
            node.child.keys.forEach {
                sum += dfs(node.child[it]!!)
            }
            return sum + node.value
        }
    }
}

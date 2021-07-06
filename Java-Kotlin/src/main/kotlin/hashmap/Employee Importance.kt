package hashmap


/**
 * https://leetcode.com/problems/employee-importance/
 * */

class Employee {
    var id: Int = 0
    var importance: Int = 0
    var subordinates: List<Int> = listOf()
}


private val map = HashMap<Int, Employee>()
fun getImportance(employees: List<Employee?>, id: Int): Int {
    employees.forEach { map[it!!.id] = it }
    return getImportance(id)
}

private fun getImportance(id: Int): Int {
    val curr = map[id]
    var total = map[id]!!.importance
    curr?.subordinates?.forEach {
        total += getImportance(it)
    }
    return total
}
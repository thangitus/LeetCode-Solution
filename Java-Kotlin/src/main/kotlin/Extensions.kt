fun <T : Comparable<T>> List<T?>.binarySearchGreaterOrEqual(
    element: T?,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int {
    var low = fromIndex
    var high = toIndex - 1
    var pos = high
    while (low < high) {
        val mid = (low + high).ushr(1) // safe from overflows
        val midVal = get(mid)
        val cmp = compareValues(midVal, element)

        when {
            cmp < 0 -> low = mid + 1
            else -> {
                pos = mid
                high = mid
            }
        }
    }
    return pos
}
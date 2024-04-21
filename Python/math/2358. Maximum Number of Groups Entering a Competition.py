from typing import List


class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        res, group_size, n = 0, 1, len(grades)
        while n >= group_size:
            res += 1
            n -= group_size
            group_size += 1
        return res

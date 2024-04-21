from typing import List


class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        def valid(n):
            idx, prev_sum = 0, 0
            for num_student in range(1, n + 1):
                count = 0
                while idx < len(grades) and count < num_student:
                    idx += 1
                    count += 1
                if count < num_student:
                    return False

            return True

        left, right, res = 1, len(grades), 1
        while left <= right:
            mid = (left + right) // 2
            if valid(mid):
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        return res

from typing import List


class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count = [0, 0]
        for student in students:
            count[student] += 1
        for sandwich in sandwiches:
            if count[sandwich] > 0:
                count[sandwich] -= 1
            else:
                break
        return sum(count)
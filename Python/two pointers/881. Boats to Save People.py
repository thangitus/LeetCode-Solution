from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        left, right, res = 0, len(people) - 1, 0
        while left <= right:
            if people[left] + people[right] <= limit:
                left += 1
            right -= 1
            res += 1
        return res

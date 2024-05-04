from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        bucket = [0] * (limit + 1)
        for person in people:
            bucket[person] += 1
        left, right, res = 1, limit, 0
        while left <= right:
            while left <= right and bucket[left] == 0:
                left += 1
            while left <= right and bucket[right] == 0:
                right -= 1
            if bucket[left] <= 0 and bucket[right] <= 0:
                break
            bucket[right] -= 1
            if left + right <= limit:
                bucket[left] -= 1
            res += 1
        return res

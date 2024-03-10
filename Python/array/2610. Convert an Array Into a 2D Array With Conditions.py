from typing import List


class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
        res = [[] for _ in range(max(count.values()))]
        for num, freq in count.items():
            for i in range(freq):
                res[i].append(num)
        return res

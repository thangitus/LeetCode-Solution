from typing import List


class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        indices, res = {}, [0] * len(nums)
        for i, num in enumerate(nums):
            indices.setdefault(num, [])
            indices[num].append(i)
        for num, indexes in indices.items():
            total, prefix_sum = sum(indexes), 0

            for i in range(len(indexes)):
                index = indexes[i]
                postfix_sum = total - prefix_sum - index
                res[index] += index * i
                res[index] -= prefix_sum

                res[index] -= index * (len(indexes) - i - 1)
                res[index] += postfix_sum

                prefix_sum += index
        return res


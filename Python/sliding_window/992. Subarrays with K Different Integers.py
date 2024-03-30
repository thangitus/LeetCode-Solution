from typing import List


class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        def at_most(n: int) -> int:
            count, left, res = {}, 0, 0
            for i in range(len(nums)):
                count[nums[i]] = count.get(nums[i], 0) + 1
                while len(count) > n:
                    count[nums[left]] -= 1
                    if count[nums[left]] == 0:
                        del count[nums[left]]
                    left += 1
                res += i - left + 1
            return res

        return at_most(k) - at_most(k - 1)

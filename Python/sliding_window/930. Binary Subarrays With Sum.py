from typing import List


class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        def sliding_at_most(mini_goal):
            left, cur_sum, res = 0, 0, 0
            for right in range(len(nums)):
                cur_sum += nums[right]
                while left <= right and cur_sum > mini_goal:
                    cur_sum -= nums[left]
                    left += 1
                res += (right - left + 1)

            return res

        return sliding_at_most(goal) - sliding_at_most(goal - 1)

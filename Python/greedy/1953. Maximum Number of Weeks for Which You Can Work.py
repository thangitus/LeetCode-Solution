import math
from typing import List


class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        total = sum(milestones)
        max_milestone = max(milestones)
        if max_milestone > math.ceil(total / 2):
            return 2 * (total - max_milestone) + 1
        else:
            return total

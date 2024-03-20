class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        res, count_zero, count_one = 0, 0, 0
        for char in s:
            if char == "0":
                if count_one > 0:
                    count_zero = count_one = 0
                count_zero += 1
            else:
                count_one += 1
                res = max(res, min(count_zero, count_one) * 2)
        return res

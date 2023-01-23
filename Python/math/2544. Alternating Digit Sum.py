class Solution:
    def alternateDigitSum(self, n: int) -> int:
        res, sign, s = 0, 1, str(n)
        for c in s:
            res += sign * int(c)
            sign *= -1
        return res

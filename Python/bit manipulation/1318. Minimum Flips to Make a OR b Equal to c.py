class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        res = 0
        while a or b or c:
            bit_a, bit_b = a & 1, b & 1,
            if c & 1:
                res += 0 if bit_a or bit_b else 1
            else:
                res += (bit_a + bit_b)
            a, b, c = a >> 1, b >> 1, c >> 1
        return res

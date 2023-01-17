class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        count_one, flip = 0, 0
        for c in s:
            if c == '1':
                count_one += 1
            else:
                flip += 1

            flip = min(flip, count_one)
        return flip

class Solution:
    def minMaxDifference(self, num: int) -> int:
        num, i = str(num), 0
        while i < len(num) - 1 and num[i] == '9': i += 1
        return int(num.replace(num[i], '9')) - int(num.replace(num[0], '0'))

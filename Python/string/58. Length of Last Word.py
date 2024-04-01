class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] != ' ':
                count += 1
            elif count > 0:
                break
        return count

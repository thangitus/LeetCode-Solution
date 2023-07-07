class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def sliding(c) -> int:
            left, right, count, res = 0, 0, 0, 0
            for right in range(len(answerKey)):
                if answerKey[right] != c:
                    count += 1
                while count > k:
                    if answerKey[left] != c:
                        count -= 1
                    left += 1
                res = max(res, right - left + 1)
            return res

        return max(sliding('T'), sliding('F'))
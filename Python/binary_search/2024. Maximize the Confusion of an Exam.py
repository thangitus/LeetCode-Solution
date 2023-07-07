import collections


class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def valid(n) -> bool:
            count = collections.Counter(answerKey[:n])
            if min(count['T'], count['F']) <= k:
                return True

            for i in range(n, len(answerKey)):
                count[answerKey[i]] += 1
                count[answerKey[i - n]] -= 1
                if min(count['T'], count['F']) <= k:
                    return True
            return False

        left, right = k, len(answerKey)
        while left < right:
            mid = (left + right + 1) // 2
            if valid(mid):
                left = mid
            else:
                right = mid - 1
        return left


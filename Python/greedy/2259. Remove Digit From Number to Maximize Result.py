class Solution(object):
    def removeDigit(self, number, digit):
        prev, last = '', -1
        for i in range(len(number)):
            if number[i] == digit:
                if i == len(number) - 1:
                    return prev
                if number[i + 1] > digit:
                    return prev + number[i + 1:]
                last = i
            prev += number[i]
        return number[:last] + number[last + 1:]

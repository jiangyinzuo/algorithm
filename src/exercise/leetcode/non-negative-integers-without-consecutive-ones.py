from functools import cache


class Solution:

    @cache
    def digital_dp(self, n: int, width: int, prev_digit: int, limited: bool):
        if width == 0:
            return 1
        digit = (n >> (width - 1)) & 1
        result = 0
        if digit == 0 and limited:
            result += self.digital_dp(n, width - 1, 0, limited)
        else:  # digit == 1
            result += self.digital_dp(n, width - 1, 0, False)
            if prev_digit == 0:
                result += self.digital_dp(n, width - 1, 1, limited)
        return result

    def findIntegers(self, n: int) -> int:
        def get_width(n: int):
            width: int = 0
            while n:
                n >>= 1
                width += 1
            return width

        width = get_width(n)
        return self.digital_dp(n, width, 0, True)


# Problem: https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/description/
# 数位DP
# Test cases
print(Solution().findIntegers(1))
print(Solution().findIntegers(2))

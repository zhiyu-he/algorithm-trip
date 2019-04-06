# -*- coding: utf-8 -*-


'''
    TIPS: X = X & (X-1) # 消除最后的一个1
    负数的表达: https://stackoverflow.com/questions/20766813/how-to-convert-signed-to-unsigned-integer-in-python
'''

class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = 0
        if n < 0:
            n = n + 2**32
        while n:
            n = n & (n-1)
            cnt += 1
        return cnt


if __name__ == '__main__':
    obj = Solution()
    print obj.hammingWeight(24)
    print obj.hammingWeight(-3)
    pass

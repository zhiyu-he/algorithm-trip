# -*- coding: utf-8 -*-

'''
    TIPS: x & (x-1), 2^n, 有且仅有一个1
    SLOVE:
        1. mod
        2. x & (x-1) && x != 0
'''

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 0:
            return False
        if n == 1:
            return True
        if n != 0 and n & (n-1) == 0:
            return True
        return False



if __name__ == '__main__':
    obj = Solution()
    print obj.isPowerOfTwo(1)
    print obj.isPowerOfTwo(16)
    print obj.isPowerOfTwo(218)
    print obj.isPowerOfTwo(-16)
    print obj.isPowerOfTwo(0)
    pass

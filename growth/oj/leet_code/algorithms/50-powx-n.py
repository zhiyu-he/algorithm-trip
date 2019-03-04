# -*- coding: utf-8 -*-


'''
	1. 直接调lib
	2. 暴力
	3. 需要注意点是, 为奇数的时候, 需要乘上一个x
'''

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
        	return 1
        if n < 0:
        	n = -n
        	x = 1/x
        r = 1
        while n:
        	if n & 1:
        		r = r * x
        	x = x * x
        	n = n >> 1
        return r




if __name__ == '__main__':
	obj = Solution()
	print obj.myPow(2.00000, 10)
	print obj.myPow(2.00000, -2)
	print obj.myPow(2.10000, 3)
	print obj.myPow(2.00000, 1)


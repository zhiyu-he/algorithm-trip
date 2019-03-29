# -*- coding: utf-8 -*-

'''
    1. 如何选取左右边界
    2. 如何确定迭代次数
    3. 如何确定相等
'''

class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 1 or x == 0:
            return x
        i = 0
        low_bound = 0
        up_bound = float(x)
        first_start = True
        _tmp = x
    	while (_tmp >= 0 and _tmp < 1e-4) is False:
            sqrt = (up_bound - low_bound) / 2 + low_bound
	    _tmp = sqrt * sqrt - x
            #print "x: %d  sqrt: %.5f _tmp: %.5f\n" % (x, sqrt, _tmp)
	    if _tmp >= 0 and _tmp < 1e-4:
		break
	    elif _tmp > 0:
                up_bound = sqrt
	    else:
                low_bound = sqrt
	    i += 1
	return int(sqrt)
	


if __name__ == '__main__':
    obj = Solution()
    print obj.mySqrt(64)
    print obj.mySqrt(8)
    print obj.mySqrt(36)
    print obj.mySqrt(81)
    pass

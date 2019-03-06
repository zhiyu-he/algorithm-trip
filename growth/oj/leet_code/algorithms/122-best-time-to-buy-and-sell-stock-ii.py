# -*- coding: utf-8 -*-

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices is None or len(prices) == 0:
        	return 0

        profit = 0
        longest_incr = None
        buy_in = prices[0]
        i = 1
        while i < len(prices):
        	if prices[i] > prices[i-1]:
        		longest_incr = prices[i]
        		i += 1
        	else:
        		_profit = longest_incr - buy_in if longest_incr else 0
        		if _profit > 0:
        			profit += _profit
        		buy_in = prices[i]
        		longest_incr = None
        		i += 1
        if longest_incr and longest_incr - buy_in > 0:
        	profit += longest_incr - buy_in
        return profit



if __name__ == '__main__':
	obj = Solution()
	print obj.maxProfit(None)
	print obj.maxProfit([])
	print obj.maxProfit([3,3])
	print obj.maxProfit([1,2,3,3,3,4,5])
	print obj.maxProfit([7,1,5,3,6,4])
	print obj.maxProfit([1,2,3,4,5])
	print obj.maxProfit([7,6,4,3,1])
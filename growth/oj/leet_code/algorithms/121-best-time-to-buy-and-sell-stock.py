# -*- coding: utf-8 -*-

'''
TIPS: 对于以第i天, 只需要知道前i-1天的min即可.
'''

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0 or len(prices) == 1:
            return 0

        min_price_end_of_i = prices[0]
        max_profit = 0
        i = 1
        while i < len(prices):
            cur_profit = prices[i] - min_price_end_of_i
            #print "price[%d]=%d - %d\n" % (i, prices[i], min_price_end_of_i)
            if max_profit < cur_profit:
                max_profit = cur_profit
            if  min_price_end_of_i > prices[i]:
                min_price_end_of_i = prices[i]
            i += 1
        return max_profit




if __name__ == '__main__':
    obj = Solution()
    print obj.maxProfit([7,1,5,3,6,4])
    print obj.maxProfit([1,1,1])
    print obj.maxProfit([7,6,4,3,1])
    print obj.maxProfit([-1, 0, -3])
    pass

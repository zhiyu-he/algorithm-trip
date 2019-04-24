# -*- coding: utf-8 -*-

'''
    TIPS: 
        1. 定义(buy, sell), 当我们未卖出时, 我们的收益是负数, 即 profit = -buy_in = -(prices[i])
        2. 对于操作中涉及的因素, 第i天, 第j次交易, 交易的类型是buy or sell
        3. 因此对于此问题的dp方程可以用一个三维数组表达. dp[i][j][k]
            3.1 i [0, len(prices)-1]
                j [0, ...]
                k [0, 1] 0 代表buy, 1: sell
'''
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp = []
        for i in range(len(prices)):
            dp.append([])
            for j in range(2):
                dp[i].append([])
                for k in range(2):
                    dp[i][j].append([])
        print dp
	


if __name__ == '__main__':
    obj = Solution()
    print obj.maxProfit([1,2,3])
    pass

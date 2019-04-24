# -*- coding: utf-8 -*-

'''
    TIPS: 
        1. 定义(buy, sell), 当我们未卖出时, 我们的收益是负数, 即 profit = -buy_in = -(prices[i])
        2. 对于操作中涉及的因素, 第i天, 第j次交易, 交易的类型是buy or sell
        3. 因此对于此问题的dp方程可以用一个三维数组表达. dp[i][j][k]
            3.1 i [0, len(prices)-1]
                j [0, ...]
                k [0, 1] 0 代表buy, 1: sell
            3.2 因此递推方程可以表达为
                dp[i][k][0] = max{
                                a. dp[i-1][k][0]                    # 即当天和上一天一样. 什么也不操作
                                [*]b. dp[i-1][k-1][1] + (prices[i])    # 在这一天进行sell out操作
                            }
                dp[i][k][1] = max{
                                a. dp[i-1][k][1]
                                [*]b. dp[i-1][k][0] + (-prices[i])   # 在这天可以buy in
                            }
                这里需要注意的是, [*], 为什么是k-1, 当前是第k手交易, 那么第k手一定来源于k-1, 那么思考k-1的状态空间{buy_in, sell_out}
                这里的另一个注意点是, 对于buy操作, 是第k次买入的时机对比. 卖出时才需要考虑上一次的买入.
                对k的定义需要在明确下, 卖出需要的是上一次买入的状态. 买入则不需要
'''
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices: return 0
        res = 0
        maxint = 9223372036854775807
        dp = []
        for i in range(len(prices)+1):
            dp.append([])
            for k in range(3):
                dp[i].append([0, 0])
                for j in range(2):
                    dp[i][k][j] = 0
        # initial for day-one
        dp[0][0][0], dp[0][0][1] = 0, -prices[0]
        dp[0][1][0], dp[0][1][1] = -maxint, -maxint
        dp[0][2][0], dp[0][2][1] = -maxint, -maxint

        for i in range(1, len(prices)):
            dp[i][0][0] = dp[i-1][0][0]
            dp[i][0][1] = max(
                        dp[i-1][0][1],
                        dp[i-1][0][0]+(-prices[i])
                    )
            dp[i][1][0] = max(
                        dp[i-1][1][0],
                        dp[i-1][0][1]+prices[i]
                    )
            dp[i][1][1] = max(
                        dp[i-1][1][1],
                        dp[i-1][1][0]+(-prices[i])
                    )
            dp[i][2][0] = max(
                        dp[i-1][2][0],
                        dp[i-1][1][1]+prices[i]
                    )
            dp[i][2][1] = max(
                        dp[i-1][2][1],
                        dp[i-1][2][0]+(-prices[i])
                    )
            res = max(res, dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1], dp[i][2][0], dp[i][2][1])
        #print dp   
        return res


if __name__ == '__main__':
    obj = Solution()
    print obj.maxProfit([1,2,3])
    print obj.maxProfit([3,3,5,0,0,3,1,4])
    print obj.maxProfit([1,2,3,4,5])
    print obj.maxProfit([7,6,4,3,1])
    pass


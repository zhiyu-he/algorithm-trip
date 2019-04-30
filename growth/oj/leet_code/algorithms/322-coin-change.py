# -*- coding: utf-8 -*-

'''
    TIPS: 递推方程很简单, dp[i]代表构成i元需要的硬币数量, 需要指出的是当无法构成i元的时, dp[i] = 0
    TODO:
        1. 内存上的优化
        2. 速度上的优化
'''

class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if len(coins) == 0:
            return -1
        if amount == 0:
            return 0

        dp = [0] * (amount+1)

        i = 1
        while i <= amount:
            for x in coins:
                if i - x >= 0:
                    if (i - x == 0) or (dp[i-x]>0):
                        dp[i] = min(dp[i-x]+1, dp[i]) if dp[i] > 0 else dp[i-x]+1
            i += 1
        #print dp
        return dp[amount] if dp[amount] > 0 else -1

if __name__ == '__main__':
    obj = Solution()
    print obj.coinChange([1,2,5], 11)
    print obj.coinChange([2], 3)
    print obj.coinChange([1], 0)
    pass

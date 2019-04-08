# -*- coding: utf-8 -*-



'''
    TIPS:
        n = 1, dp[1] = 1
        n = 2, dp[2] = 2
        n = 3, dp[n-1] + dp[n-2] = 2 + 1 = 3 {(1,1,1), (1,2), (2, 1)}
        n = 4, dp[n-1] + dp[n-2] = 3 + 2 = 5
'''

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0, 1, 2]
        step = 3
        while step <= n:
            dp.append(dp[step-1]+dp[step-2])
            step += 1
        return dp[n]




if __name__ == '__main__':
    obj = Solution()
    print obj.climbStairs(3)
    print obj.climbStairs(2)
    print obj.climbStairs(1)
    print obj.climbStairs(10)
    pass

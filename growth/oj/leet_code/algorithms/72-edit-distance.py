# -*- coding: utf-8 -*-

'''
    TIPS: define dp[i][j] = cost, measn words1 form [0...i] same to words2 from [0...j]  cost
        dp[1][1] = word1[1] same to word2[1]
        dp[0][1], dp[0, 0] dp[1, 0]
        即处理word1, dp[0][1], handle word2 dp[1][0], 同时处理word1, word2 dp[0][0]

'''

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        dp = []
        for i in range(len(word1)+1):
            dp.append([])
            dp[i] = [0] * (len(word2)+1)

        for i in range(len(word1)+1):
            dp[i][0] = i
        for j in range(len(word2)+1):
            dp[0][j] = j

        i = 1
        while i <= len(word1):
            j = 1
            while j <= len(word2):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    k1 = dp[i-1][j]
                    k2 = dp[i][j-1]
                    k3 = dp[i-1][j-1]
                    dp[i][j] = min(k1, k2, k3) + 1
                j += 1
            i += 1
        #print dp[1][1]
        #print dp
        return dp[len(word1)][len(word2)]

if __name__ == '__main__':
    obj = Solution()
    print obj.minDistance("horse", "ros")
    print obj.minDistance("intention", "execution")
    pass

# -*- coding: utf-8 -*-

'''
    TIPS: calcs common longest sequence.
    dp[i][j] = max(
            dp[i-1][j],
            dp[i][j-1],
            dp[i-1][j-1] + 1 if s1[i] == s2[j]
        )
    then. len(str1) - cls + len(str2) - cls
'''


class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        cls = self.cls(word1, word2)
        return len(word1) + len(word2) - cls - cls


    def cls(self, word1, word2):
        dp = []
        for i in xrange(len(word1)+1):
            dp.append([])
            dp[i] = [0] * (len(word2)+1)
        i = 1
        j = 1
        while i - 1 < len(word1):
            j = 1
            while j - 1< len(word2):
                k1 = dp[i-1][j]
                k2 = dp[i][j-1]
                k3 = dp[i-1][j-1]+1 if word1[i-1] == word2[j-1] else 0
                dp[i][j] = max(k1, k2, k3)
                #print dp[i][j]
                j += 1
            i += 1
        return dp[len(word1)][len(word2)]



if __name__ == '__main__':
    obj = Solution()
    print obj.minDistance("abc", "bca")
    print obj.minDistance("city", "college")
    print obj.minDistance("abadsfaf", "ajfkfjj")

    pass

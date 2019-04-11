# -*- coding: utf-8 -*-

class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle) == 0:
            return 0
        if len(triangle) == 1:
            return triangle[0][0]
        N = len(triangle)
        DP = []
        # for initial
        for x in triangle[N-1]:
            DP.append(x)
        
        level = N - 2
        while level >= 0:
            idx = 0
            while idx <= level:
                delta = min(DP[idx], DP[idx+1])
                #print "level: %d i1: %d i2: %d delta: %d\n" % (level, idx, idx+1, delta)
                DP[idx] = triangle[level][idx] + delta
                idx += 1
            #print "level: %d DP: %s\n" % (level, DP)
            level -= 1
        return DP[0]
        

if __name__ == '__main__':
    obj = Solution()
    input1= [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
    ]
    print obj.minimumTotal(input1)
    print obj.minimumTotal([])
    print obj.minimumTotal([[1]])
    input2 = [
                [2],
                [1,2]
            ]
    print obj.minimumTotal(input2)
    input3 = [[-1],[2,3],[1,-1,-3]]
    print obj.minimumTotal(input3)
    pass

# -*- coding: utf-8 -*-

class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        global_max = max(nums)
        magic_number = 'a'
        DP = []
        n = len(nums)
        for i in range(n):
            DP.append([])
            for j in range(n):
                if i == j:
                    DP[i].append(nums[i])
                else:
                    DP[i].append(magic_number)
        # DP[i][j] i->j的连续乘积
        i = 1
        while i < n:
            DP[0][i] = DP[0][i-1]*nums[i]
            i += 1
        i = 1
        while i < n:
            j = i + 1
            while j < n:
                # DP[i-1][j] DP[i][j] DP[1][2] DP[0][2]
                DP[i][j] = DP[i-1][j]/nums[i]
                print "DP[%d][%d]=%d\t" % (i, j, DP[i][j])
                global_max = max(global_max, DP[i][j])
                j += 1
            print "\n"
            i += 1
        #print DP
        return global_max


if __name__ == '__main__':
    obj = Solution()
    #print obj.maxProduct([-1,-2,-3,-4,-5,-7,-8,-9,-10])
    print obj.maxProduct([-2,0,-1])
    print obj.maxProduct([-1,-2,-2,-1])
    print obj.maxProduct([0,-1])
    print obj.maxProduct([-1])
    print obj.maxProduct([-3,-1,-4])
    print obj.maxProduct([-2,3,-4])
    print obj.maxProduct([0,2])
    pass

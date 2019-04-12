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
        global_max = nums[0]
        DP = []
        for step in range(len(nums)+1):
            DP.append([])
        DP[1].append(nums[0])
        j = 1
        while j < len(nums):
            step_i = 1
            while step_i <= j+1:
                #print "handle DP[%d][%d]\n" % (step_i, j)
                cur_val = 0
                if step_i == 1:
                    cur_val = nums[j]
                elif step_i - 1 == j:
                    cur_val = DP[step_i-1][0]*nums[j]
                else:
                    #print "branch3, step_i=%d j=%d j-step_i+1=%d\n" % (step_i, j, j-step_i+1)
                    cur_val = DP[step_i-1][j-step_i+1]*nums[j]

                global_max = max(global_max, cur_val)
                DP[step_i].append(cur_val)
                step_i += 1
            #print "j: %d DP: %s\n" % (j, DP)
            j += 1
        return global_max


if __name__ == '__main__':
    obj = Solution()
    #print obj.maxProduct([-1,-2,-3,-4,-5,-7,-8,-9,-10])
    print obj.maxProduct([2,3,-2,4])
    print obj.maxProduct([-2,0,-1])
    print obj.maxProduct([-1,-2,-2,-1])
    print obj.maxProduct([0,-1])
    print obj.maxProduct([-1])
    print obj.maxProduct([-3,-1,-4])
    print obj.maxProduct([-2,3,-4])
    print obj.maxProduct([0,2])
    pass

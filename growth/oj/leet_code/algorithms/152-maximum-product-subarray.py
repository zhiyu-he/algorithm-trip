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
        max_array = [0] * len(nums)
        min_array = [0] * len(nums)
        max_array[0] = min_array[0] = nums[0]

        i = 1;
        while i < len(nums):
            max_array[i] = max(max_array[i-1]*nums[i], nums[i], min_array[i-1]*nums[i])
            min_array[i] = min(max_array[i-1]*nums[i], nums[i], min_array[i-1]*nums[i])
            global_max = max(global_max, max_array[i], min_array[i])
            i += 1
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

# -*- coding: utf-8 -*-

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        ans = []
        index = []
        for i, val in enumerate(nums):
            if index and i - index[0] >= k:
                index.pop(0)
            while index and nums[index[-1]] < val:
                index.pop(-1)
            index.append(i)
            if i >= k-1:
                ans.append(nums[index[0]])
        return ans

if __name__ == '__main__':
    obj = Solution()
    print obj.maxSlidingWindow([1,3,1,2,0,5], 3)

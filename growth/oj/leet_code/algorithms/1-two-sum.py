# -*- coding: utf-8 -*-

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ans = []
        s = {}
        for idx,num in enumerate(nums):
            s[num] = idx
        for i in range(len(nums)):
            other = target - nums[i]
            if other in s and s[other] != i:
                ans.append(i)
                ans.append(s[other])
                del s[other]
                if nums[i] in s:
                    del s[nums[i]]
        return ans


if __name__ == '__main__':
    obj = Solution()
    print obj.twoSum([3,3], 6)


# -*- coding: utf-8 -*-


class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()

        res = set()
        for i, a in enumerate(nums[:-2]): # 因为要3个数才构成一组解
        	l = i + 1
        	r = len(nums) - 1
        	while l < r:
        		tmp = nums[l] + nums[r]
        		if tmp == -a:
        			res.add((a, nums[l], nums[r]))
        			l += 1
        			r -= 1
        			while l < len(nums)-1 and nums[l] == nums[l-1] and r > 0 and nums[r] == nums[r+1]:
        				l += 1
        				r -= 1
        		elif tmp > -a:
        			r -= 1
        		else:
        			l += 1
        return map(list, res)


if __name__ == '__main__':
	obj = Solution()
	print obj.threeSum([-1, 0, 1, 2, -1, -4])
	print obj.threeSum([-1, 0, 1, -1, 0, 1])
	print obj.threeSum([-2,0,1,1,2])
	print obj.threeSum([-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6])

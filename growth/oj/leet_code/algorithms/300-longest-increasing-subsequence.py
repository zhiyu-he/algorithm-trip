# -*- coding: utf-8 -*-

'''
    TIPS: 对于每个sequence[i], can be effect on the suffix which suffix sequence less then sequence[i].
        so, as we can see, we may be can binary search for suffix, we effect on.
'''

class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
	if len(nums) == 0: return 0
        max_lis = 1
	dp = [1]*len(nums) # dp[i] means suffix with nums[i] max length
	i = 1
	while i < len(nums):
	    for j in range(i):
		if nums[i] > nums[j]:
		    dp[i] = max(dp[j]+1, dp[i])
            max_lis = max(max_lis, dp[i])
	    i += 1
	return max_lis


if __name__ == '__main__':
    obj = Solution()
    print obj.lengthOfLIS([10,9,2,5,3,7,101,18])
    print obj.lengthOfLIS([])
    print obj.lengthOfLIS([0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15])
    pass

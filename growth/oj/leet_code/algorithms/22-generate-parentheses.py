# -*- coding: utf-8 -*-


'''
	TIPS: 
	n = 1, left=1 right= 1

'''

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 0:
        	return []
        if n == 1:
        	return ["()"]

        return self.dfs(0, 0, "", [], n)

    def dfs(self, left_cnt, right_cnt, str, r_list, target_n):

    	if len(str) + 1 == target_n * 2:
    		str += ")"
    		r_list.append(str)
    		return r_list
    	if left_cnt == 0:
    		str += "("
    		self.dfs(left_cnt+1, right_cnt, str, r_list, target_n)
    	elif left_cnt < target_n and left_cnt > right_cnt:
    		self.dfs(left_cnt+1, right_cnt, str + "(", r_list, target_n)
    		self.dfs(left_cnt, right_cnt+1, str + ")", r_list, target_n)
    	elif left_cnt < target_n:
    		self.dfs(left_cnt+1, right_cnt, str + "(", r_list, target_n)
    	else:
    		if right_cnt < target_n:
    			str += ")"
    			self.dfs(left_cnt, right_cnt+1, str,r_list, target_n)
    	return r_list
        

if __name__ == '__main__':
	obj = Solution()
	print obj.generateParenthesis(3)
	print obj.generateParenthesis(1)
	print obj.generateParenthesis(0)
	print obj.generateParenthesis(4)
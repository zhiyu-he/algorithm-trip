# -*- coding: utf-8 -*-

# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
    	if root is None:
    		return 0

    	return self.dfs(root, 1, -1)
    

    def dfs(self, node, level, min_depth):
        if node is None:
        	return min_depth
       	if node.left is None and node.right is None:
            if min_depth == -1:
            	min_depth = level
            else:
                min_depth = min(min_depth, level)
            return min_depth

        depth1 = self.dfs(node.left, level+1, min_depth)
        depth2 = self.dfs(node.right, level+1, min_depth)
        if depth1 > -1 and depth2 > -1:
        	return min(depth1, depth2)
        else:
        	return max(depth1, depth2)
if __name__ == '__main__':
	node = TreeNode(1)
	node.left = TreeNode(2)
	node.left.left = TreeNode(3)
	node.left.left.left = TreeNode(4)
	node.left.left.left.left = TreeNode(5)

	obj = Solution()
	print obj.minDepth(node)
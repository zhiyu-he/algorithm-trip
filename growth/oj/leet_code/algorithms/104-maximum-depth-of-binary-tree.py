# -*- coding: utf-8 -*-



# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
        	return 0
        return self.maxLevel(root, 1)

    def maxLevel(self, node, level):
    	if node is None or (node.left is None and node.right is None):
    		return level


    	l1 = self.maxLevel(node.left, level+1)
    	l2 = self.maxLevel(node.right, level+1)
    	if l1 > l2:
    		return l1
    	else:
    		return l2

if __name__ == '__main__':

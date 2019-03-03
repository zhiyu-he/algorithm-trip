# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

'''
	TIPS: 由于是二叉搜索树, 在判定的时候, 只需要考虑一边即可.
'''

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        return self.findPQ(root, p, q)
        
    def findPQ(self, root, p, q):
    	if root is None or root == p or root == q:
    		return root

    	if root.val > p.val and root.val > q.val:
    		return self.findPQ(root.left, p, q)

    	if root.val < p.val and root.val < q.val:
    		return self.findPQ(root.right, p, q)

    	return root
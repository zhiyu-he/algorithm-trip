# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

'''
TIPS:
	考虑在一棵二叉树中, p和q的关系. 
	key1: 当给定节点i, i == p or i == q时, 意味着i为最小公共父节点
	key2: 当`key1`不满足时, i, p, q 有如下三种关系
		1. (p, q) in i.left
		2. (p, q) in i.right
		3. p, p in i.left, i.right

	对于key2的场景, 1,2 退化为key1, 3则返回i即可.

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

    def findPQ(self, cur_node, p, q):
    	if cur_node is None or cur_node == p or cur_node == q:
    		return cur_node

    	a = self.findPQ(cur_node.left, p, q)
    	b = self.findpQ(cur_node.right, p, q)

    	if a is None and b:
    		return b
    	if b is None and a:
    		return a
    	if a and b:
    		return cur_node
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# https://zh.wikipedia.org/wiki/%E4%BA%8C%E5%85%83%E6%90%9C%E5%B0%8B%E6%A8%B9
# case1. 对于叶子结点, 返回True
# case2. 对于非叶子结点, root.val > 左侧最大值, root.val < 右侧最小值
# 这里需要考虑一下:
#	1. 在第一层是不需要min, max的
#   2. 树的left_node, 永远没有min, 同样的, 树的right_node, 永远没有max
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        #
        return self.helper(root, None, None)
    

    def helper(self, node, min, max):
    	"""
    	:rtype: (bool, min, max)
    	"""
    	# 当前点
    	if node is None:
    		return True
    	if min is not None and node.val <= min: 
    		return False
    	if max is not None and node.val >= max:
    		return False
    	# 站在当前点, 考虑当前点对左右子树的影响.
    	# left_tree, max(left_tree) < cur_node.val
    	# right_tree, min(right_tree) > cur_node.val
    	return self.helper(node.left, min, node.val) and self.helper(node.right, node.val, max)

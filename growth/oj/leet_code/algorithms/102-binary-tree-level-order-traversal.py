# -*- coding: utf-8 -*-

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        import Queue
        if root is None:
        	return []
        r = []
        queue = Queue.Queue()
        queue.put(root)
        r.append([root.val])
        each_layer_nodes = []
        each_layer_node_cnt = 1
        while queue.empty() == False:
            next_node = queue.get()
            if next_node.left:
                queue.put(next_node.left)
                each_layer_nodes.append(next_node.left.val)
            if next_node.right:
                queue.put(next_node.right)
                each_layer_nodes.append(next_node.right.val)
            each_layer_node_cnt -= 1
            if each_layer_node_cnt == 0:
            	if len(each_layer_nodes) > 0:
            		r.append(each_layer_nodes[:])
             	each_layer_node_cnt = len(each_layer_nodes)
            	each_layer_nodes = []
        return r
if __name__ == '__main__':
	root = TreeNode(3)
	root.left = TreeNode(9)
	root.right = TreeNode(20)
	root.right.left = TreeNode(15)
	root.right.right = TreeNode(7)
	
	obj = Solution()
	print obj.levelOrder(root)
	print obj.levelOrder(TreeNode(1))
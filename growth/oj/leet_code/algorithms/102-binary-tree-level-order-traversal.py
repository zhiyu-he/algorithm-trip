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
        while queue.empty() == False:
            qsize = queue.qsize()
            layers = []
            i = 0
            while i < qsize:
                next_node = queue.get()
                layers.append(next_node.val)
                if next_node.left:
                    queue.put(next_node.left)
                if next_node.right:
                    queue.put(next_node.right)
                i += 1
            if len(layers)  > 0:
                r.append(layers)
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

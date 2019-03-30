# -*- coding: utf-8 -*-

'''
    TIPS:
        1. 字典树的数据结构是什么样子的?
            TreeNode = char_val + is_end + {}
        2. 层级关系要如何考虑?
        3. 参数校验, query的深度与Tire的深度
        4. 如何加速
            4.1 避免不必要的分配如每一层26个TreeNode, 改成dict
'''

class TreeNode(object):
    def __init__(self):
        self.child = {}
        self.val = ''

    def __str__(self):
        return "is_end: %s has_initial: %s val: %s child: %s" % (self.is_end, self.has_initial, self.val, self.child)

class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.end_of_word = '@'
        self.root = TreeNode()
        self.max_length = 0

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        length = len(word)
        start_node = self.root
        for ch in word:
            # initial if word[i] not in table
            if ch not in start_node.child:
                start_node.child[ch] = TreeNode()
            start_node.child[ch].val = ch
            start_node = start_node.child[ch]

        if self.end_of_word not in start_node.child:
            start_node.child[self.end_of_word] = self.end_of_word
        if length > self.max_length:
            self.max_length = length



    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """

        if len(word) > self.max_length:
            return False
        start_node = self.root
        for ch in word:
            if start_node is None or ch not in start_node.child:
                return False
            start_node = start_node.child[ch]
        return self.end_of_word in start_node.child



    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        if len(prefix) > self.max_length:
            return False
        start_node = self.root
        for ch in prefix:
            if start_node is None or ch not in start_node.child:
                return False
            start_node = start_node.child[ch]
        return True

if __name__ == '__main__':
    obj = Trie()
    #obj.insert("nemathelminth")
    #param_2 = obj.search("leguminiform")
    #print obj.search("hhhhhhhhhh")
    #param_3 = obj.startsWith("app")
    #print obj.startsWith("m")
    #print param_2
    #print param_3
    #print obj.search("app")
    #print obj.insert("Tire")
    #print obj.startsWith("a")

    obj.insert("app")
    obj.insert("apple")
    obj.insert("beer")
    print obj.search("apps")
    print obj.search("app")
    pass

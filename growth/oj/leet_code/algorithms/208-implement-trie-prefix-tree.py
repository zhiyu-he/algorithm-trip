# -*- coding: utf-8 -*-

'''
    TIPS:
        1. 字典树的数据结构是什么样子的?
            TreeNode = char_val + is_end + []TreeNode
        2. 层级关系要如何考虑?
        3. 参数校验, query的深度与Tire的深度
        4. 如何加速
            4.1 避免不必要的分配如每一层26个TreeNode, 改成dict
'''

class TreeNode(object):
    def __init__(self):
        self.child = {}
        self.is_end = False
        self.has_initial = False    # use for search and startsWith api
        self.val = ''

    def __str__(self):
        return "is_end: %s has_initial: %s val: %s child: %s" % (self.is_end, self.has_initial, self.val, self.child)

class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
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
        i = 0
        while i < length:
            idx = word[i]
            # initial if word[i] not in table
            if word[i] not in start_node.child:
                start_node.child[idx] = TreeNode()
            start_node.child[idx].val = word[i]
            start_node.child[idx].has_initial = True
            if start_node.child[idx].is_end is False and i == length - 1:
                #print "fuck  word: %s ch: %s idx: %d\n" % (word, word[i], i)
                start_node.child[idx].is_end = True
            start_node = start_node.child[idx]
            i += 1
        if length > self.max_length:
            self.max_length = length



    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        search_flag = False
        start_root = self.root
        length = len(word)
        i = 0
        while i < length and length <= self.max_length:
            idx = word[i]
            #print "word: %s ch: %s idx: %s childs: %s len(child): %d\n" % (word, word[i], idx, start_root.child.get(idx, None), len(start_root.child))
            if start_root is None or idx not in start_root.child:
                # guard logic, i don't know why
                search_flag = False
                break
            if start_root.child[idx].has_initial is False:
                search_flag = False
                break
            if i == length - 1 and start_root.child[idx].is_end:
                search_flag = True
            start_root = start_root.child[idx]
            i += 1
        return search_flag



    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        start_root = self.root
        length = len(prefix)
        starts_with_flag = length <= self.max_length
        i = 0
        while i < length and starts_with_flag:
            idx = prefix[i]
            if start_root is None or idx not in start_root.child:
                # guard logic, i don't know why
                starts_with_flag = False
                break
            #print "prefix: %s ch: %s idx: %d childs: %s len(child): %d\n" % (prefix, prefix[i], idx, start_root.child[idx], len(start_root.child))
            if start_root.child[idx].has_initial is False:
                starts_with_flag = False
                break
            start_root = start_root.child[idx]
            i += 1
        return starts_with_flag

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

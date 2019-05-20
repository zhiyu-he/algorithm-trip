# -*- coding: utf-8 -*-

class Node(object):
    def __init__(self, val, key=None):
        self.val = val
        self.key = key
        self.next_p = None
        self.prev_p = None

class DLinkList(object):
    def __init__(self):
        self.head = None
        self.tail = None

    def upt(self, node):
        self.pop(node)
        self.push(node)
        
    def pop(self, node):
        if node is None:
            return
        if node.prev_p is None and node.next_p is None:
            self.head = None
            self.tail = None
            return
        p_node = node.prev_p
        n_node = node.next_p
        if p_node is None:
            # means head
            self.head = n_node
            n_node.prev_p = None
            return
        if n_node is None:
            # means tail
            self.tail = p_node
            p_node.next_p = None
            return

        p_node.next_p = n_node
        n_node.prev_p = p_node
        
        if n_node.next_p is None:
            self.tail = n_node
        if p_node.prev_p is None:
            self.head = p_node

        
    def push(self, node):
        if self.head is None and self.tail is None:
            # initial
            self.tail = node
            self.head = node
        else:
            node.next_p = self.head
            node.prev_p = None
            self.head.prev_p = node
            self.head = node

    def test_iterator(self):
        h = self.head
        print "start from head"
        while h is not None:
            print "val: %d" % h.val
            h = h.next_p

        print "start from tail"
        t = self.tail
        while t is not None:
            print "val: %d" % t.val
            t = t.prev_p






class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cap = capacity
        self.size = 0
        self.dl = DLinkList()
        self.key_2_node = {}

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.key_2_node:
            return -1
        
        node = self.key_2_node[key]
        self.dl.upt(node)
        return node.val

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        cur_size = self.size
        node = Node(value, key)
        if key in self.key_2_node:
            self.dl.pop(self.key_2_node[key])
        else:
            cur_size += 1
        if cur_size > self.cap:
            del self.key_2_node[self.dl.tail.key]
            self.dl.pop(self.dl.tail)
            
        self.key_2_node[key] = node
        self.dl.push(node)
        
        self.size = cur_size if cur_size <= self.cap else self.cap


if __name__ == '__main__':
    dl = DLinkList()
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    dl.push(n1)
    dl.push(n2)
    dl.push(n3)
    
    #   
    dl.test_iterator()

    dl.upt(n1)
    print "--------------------------\n"
    dl.test_iterator()
    
    dl.pop(n3)
    print "--------------------------\n"
    dl.test_iterator()


    cache = LRUCache(2)

    cache.put(1, 1);
    print cache.size
    cache.put(2, 2);
    print cache.size
    print cache.get(1) == 1;     #returns 1
    cache.put(3, 3);        #evicts key 2
    print cache.size
    print cache.get(2) == -1;     #returns -1 (not found)
    cache.put(4, 4);        #evicts key 1
    print cache.size
    print cache.get(1) == -1;     #returns -1 (not found)
    print cache.get(3) == 3;     #returns 3
    print cache.get(4) == 4;     #returns 4


    cache = LRUCache(1)
    cache.put(2,1)
    print cache.get(2) == 1

























# -*- coding: utf-8 -*-

class FreqNode(object):
    def __init__(self, freq_val):
        self.next_node = None
        self.prev_node = None
        self.freq_val = freq_val
        self.key_sets = set()
    def __str__(self):
        return "freq_val: %s key_sets: %s" % (self.freq_val, self.key_sets)

class DataItem(object):
    def __init__(self, val, parent):
        self.data = val
        self.parent = parent

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
        if node.prev_node is None and node.next_node is None:
            self.head = None
            self.tail = None
            return
        p_node = node.prev_node
        n_node = node.next_node
        if p_node is None:
            # means head
            self.head = n_node
            n_node.prev_node = None
            return
        if n_node is None:
            # means tail
            self.tail = p_node
            p_node.next_node = None
            return

        p_node.next_node = n_node
        n_node.prev_node = p_node

        if n_node.next_node is None:
            self.tail = n_node
        if p_node.prev_node is None:
            self.head = p_node

    def insert_after(self, node1, node2, desc=False):
        if self.head is None or self.tail is None:
            raise Exception("unexpect operation, insert_after must call when dl is not empty")

        if node1 is None and desc:
            node2.next_node = self.head
            self.head.prev_node = node2
            self.head = node2
        else:
            tmp = node1.next_node
            node1.next_node = node2
            node2.next_node = tmp
            node2.prev_node = node1
            if tmp is not None:
                tmp.prev_node = node2

            if node1.prev_node is None:
                self.head = node1

            if node2.next_node is None:
                self.tail = node2



    def push(self, node):
        if self.head is None and self.tail is None:
            # initial
            self.tail = node
            self.head = node
        else:
            node.next_node = self.head
            node.prev_node = None
            self.head.prev_node = node
            self.head = node



    def test_iterator(self):
        h = self.head
        print "start from head"
        while h is not None:
            print "val: %d" % h.val
            h = h.next_node

        print "start from tail"
        t = self.tail
        while t is not None:
            print "val: %d" % t.val
            t = t.prev_node


def new_freq_node_if_need(freq_node, cur_val):
    new_node = None
    if freq_node is None or freq_node.freq_val != cur_val:
        new_node = FreqNode(cur_val)
    return new_node



class AllOne(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.mapping = {}
        self.freq_dl = DLinkList()



    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: None
        """
        parent = None
        cur_val = None
        if key in self.mapping:
            data_item = self.mapping[key]
            parent = data_item.parent
            cur_val = data_item.data + 1
            # parent is and FreqNode
            new_node = new_freq_node_if_need(parent.next_node, cur_val)
            if new_node is None:
                parent.key_sets.remove(key)
                parent.next_node.key_sets.add(key)
                data_item.data = cur_val
                data_item.parent = parent.next_node
                if len(parent.key_sets) == 0:
                    self.freq_dl.pop(parent)
            else:
                parent.key_sets.remove(key)
                new_node.key_sets.add(key)
                data_item.data = cur_val
                data_item.parent = new_node
                self.freq_dl.insert_after(parent, new_node)
                if len(parent.key_sets) == 0:
                    self.freq_dl.pop(parent)
            self.mapping[key] = data_item
        else:
            parent = self.freq_dl.head
            if parent is None or parent.freq_val != 1:
                parent = FreqNode(1)
                self.freq_dl.push(parent)
            parent.key_sets.add(key)
            data_item = DataItem(1, parent)
            self.mapping[key] = data_item


    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: None
        """
        if key not in self.mapping:
            return None

        data_item = self.mapping[key]
        parent = data_item.parent
        cur_val = data_item.data - 1
        if data_item.data == 1:
            parent.key_sets.remove(key)
            if len(parent.key_sets) == 0:
                self.freq_dl.pop(parent)
            del self.mapping[key]
        else:
            new_node = new_freq_node_if_need(parent.prev_node, cur_val)
            if new_node is None:
                parent.key_sets.remove(key)
                parent.prev_node.key_sets.add(key)
                data_item.data = cur_val
                data_item.parent = parent.prev_node
                if len(parent.key_sets) == 0:
                    self.freq_dl.pop(parent)
            else:
                #print "cur_val: %s" % cur_val
                #print "cur_parent: %s freq_val: %s" % (parent.prev_node, parent.freq_val)
                parent.key_sets.remove(key)
                new_node.key_sets.add(key)
                data_item.data = cur_val
                data_item.parent = new_node
                self.freq_dl.insert_after(parent.prev_node, new_node, desc=True)
                if len(parent.key_sets) == 0:
                    self.freq_dl.pop(parent)



    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        if len(self.mapping) == 0:
            return ""
        for i in self.freq_dl.tail.key_sets:
            return i


    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        if len(self.mapping) == 0:
            return ""
        for i in self.freq_dl.head.key_sets:
            return i



# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()

def debug(obj, seq=1):
    print "seq: %s" % seq
    print obj.mapping
    print obj.freq_dl.head
    print obj.freq_dl.tail
    print obj.getMinKey()
    print obj.getMaxKey()



if __name__ == '__main__':
    obj = AllOne()
    obj.inc("123")
    obj.inc("123")
    obj.inc("qqq")
    obj.dec("123")
    obj.inc("bbb")
    obj.inc("bbb")
    obj.inc("bbb")
    for k in obj.mapping:
        v = obj.mapping[k]
        print "k: %s val: %s" % (k, v.data)
    print "======="

    print "max: %s min: %s" % ( obj.getMaxKey() == "bbb", obj.getMinKey() in {"qqq", "123"})
    obj.dec("123")

    for k in obj.mapping:
        v = obj.mapping[k]
        print "k: %s val: %s" % (k, v.data)

    print "======="
    obj.dec("qqq")
    for k in obj.mapping:
        v = obj.mapping[k]
        print "k: %s val: %s" % (k, v.data)

    print "======="
    print "max: %s min: %s" % (obj.getMaxKey() == "bbb", obj.getMinKey() in {"123"})

    '''
["AllOne","inc","inc","inc","inc","inc","dec","getMaxKey","getMinKey","inc","inc","inc","getMaxKey","getMinKey","inc","inc","getMinKey"]
[[],["hello"],["hello"],["world"],["world"],["hello"],["world"],[],[],["world"],["world"],["leet"],[],[],["leet"],["leet"],[]]
    '''
    obj = AllOne()
    obj.inc("hello")
    obj.inc("hello")
    obj.inc("world")
    obj.inc("world")
    obj.inc("hello")
    obj.dec("world")
    print obj.getMaxKey() == "world"
    print obj.getMinKey()
    obj.inc("world")
    obj.inc("world")
    obj.inc("leet")
    obj.inc("leet")
    obj.inc("leet")

    obj = AllOne()
    obj.inc("hello")
    obj.inc("hello")
    print obj.getMaxKey()
    print obj.getMinKey()
    print obj.freq_dl.head
    pass

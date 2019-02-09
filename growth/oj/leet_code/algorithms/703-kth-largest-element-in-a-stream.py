#-*- coding: utf-8 -*-
class Comparator:
    def __init__(self, val):
        self.val = val

    def __lt__(self, other):
        return self.val > self.other

    def __eq__(self, other):
        return self.val == self.other

    def __str__(self):
        return str(self.val)

import heapq
class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        import heapq
        self.k = k
        self.nums = nums
        self.min_heap = []
        count = 0
        for i in nums:
            if count < k:
                heapq.heappush(self.min_heap, i)
            else:
                if i > self.min_heap[0]:
                    heapq.heappop(self.min_heap)
                    heapq.heappush(self.min_heap, i)
            count += 1
        
        

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        if len(self.min_heap) < self.k or val > self.min_heap[0]:
            if len(self.min_heap) == self.k:
                heapq.heappop(self.min_heap)
            heapq.heappush(self.min_heap, val)
        return self.min_heap[0]
        

if __name__ == '__main__':
    obj = KthLargest(1, [])
    print obj.add(-3)
    print obj.add(-2)
    print obj.add(-4)
    print obj.add(0)
    print obj.add(4)

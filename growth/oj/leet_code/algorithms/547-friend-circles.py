# -*- coding: utf-8 -*-


'''
    TIPS: 有两种办法
        1) 利用并查集的办法
        2) 染色问题

        对于方法1). 我们要考虑
            a. 并查集如何定义?

'''
class UnionFind(object):
    def __init__(self, N):
        self.roots = [0] * N
        for i in range(N):
            self.roots[i] = i

    def find_roots(self, i):
        root = i
        while root != self.roots[root]:
            root = self.roots[root]
        # 路径压缩, 用于提升速度, TODO: 补充一个path compress
        while i != self.roots[i]:
            tmp = self.roots[i]
            self.roots[i] = root
            i = tmp
            pass
        return root

    def connected(self, p, q):
        return self.find_roots(p) == self.find_roots(q)

    def union(self, p, q):
        p_root = self.find_roots(p)
        q_root = self.find_roots(q)
        # p<-q
        self.roots[q_root] = p_root
        #print "union, p:%d, q:%d %s\n" % (p, q, self.roots)

    def count_roots(self):
        cnt = 0
        for i in range(len(self.roots)):
            if i == self.roots[i]:
                cnt += 1
        #print self.roots
        return cnt

class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        #print num
        #print record_land
        uf = UnionFind(len(M))

        for raw in range(len(M)):
            col = raw+1
            while col < len(M):
                #print "handle: %d %d\n" % (raw, col)
                if M[raw][col] == 1:
                    uf.union(raw, col)
                col += 1
        return uf.count_roots()

if __name__ == '__main__':
    obj = Solution()
    print obj.findCircleNum([
			[1, 1, 1, 1, 0],
                    	[1, 1, 0, 1, 0],
                    	[1, 1, 0, 0, 0],
                    	[0, 0, 0, 0, 0]])

    print obj.findCircleNum([
			[1,1,0],
			[1,1,0],
			[0,0,1]])
    print obj.findCircleNum([
                    	[1,1,0],
			[1,1,1],
			[0,1,1]])
    print obj.findCircleNum([
                    	[1,0,0,1],
			[0,1,1,0],
                        [0,1,1,1],
			[1,0,1,1]])


    pass

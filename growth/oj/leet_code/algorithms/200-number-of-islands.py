# -*- coing: utf-8 -*-
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
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        num = 0
        record_land = {}
        for raw in range(len(grid)):
            for col in range(len(grid[raw])):
                if grid[raw][col] == '0':
                    continue
                record_land[(raw, col)] = num
                num += 1
        #print num
        #print record_land
        uf = UnionFind(num)

        for raw in range(len(grid)):
            for col in range(len(grid[raw])):
                if grid[raw][col] == '0':
                    continue
                # handle (raw, col - 1)
                if col - 1  >= 0 and grid[raw][col-1] == '1':
                    uf.union(record_land[(raw, col-1)], record_land[(raw, col)])
                if raw - 1 >= 0 and grid[raw-1][col] == '1':
                    uf.union(record_land[(raw-1, col)], record_land[(raw, col)])

        return uf.count_roots()

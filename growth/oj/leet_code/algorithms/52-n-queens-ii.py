# -*- coding: utf-8 -*-

        
class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        global_list = []
        self.slove(n, global_list, [], 0, set(), set(), set())
        return len(global_list)

    def slove(self, n, global_list, l, cur_row, pie, cols, nai):
        if cur_row == n:
            global_list.append(l[:])
            return
        start_col = 0
        while start_col < n:
            point = (cur_row, start_col)
            if point not in pie and point not in cols and point not in nai:
                l.append(start_col)
                self.add_conflict(n, point, pie, cols, nai)
                self.slove(n, global_list, l, cur_row + 1, pie, cols, nai)
                self.remove_conflict(n, point, pie, cols, nai)
                l.pop(len(l)-1 )
            start_col += 1
        return


    def add_conflict(self, n, point, pie, cols, nai):
        row_i = point[0]
        col_j = point[1]

        sum_i_j = row_i + col_j
        next_row = row_i + 1
        while next_row < n and sum_i_j - next_row >= 0:
            pie.add((next_row, sum_i_j - next_row))
            next_row += 1

        next_row = row_i + 1
        div_i_j = row_i - col_j
        while next_row < n and next_row - div_i_j < n:
            nai.add((next_row, next_row - div_i_j))
            next_row += 1

        next_row = row_i + 1
        while next_row < n:
            cols.add((next_row, col_j))
            next_row += 1

    def remove_conflict(self, n, point, pie, cols, nai):
        row_i = point[0]
        col_j = point[1]

        sum_i_j = row_i + col_j
        next_row = row_i + 1
        while next_row < n and sum_i_j - next_row >= 0:
            pie.remove((next_row, sum_i_j - next_row))
            next_row += 1

        next_row = row_i + 1
        div_i_j = row_i - col_j
        while next_row < n and next_row - div_i_j < n:
            nai.remove((next_row, next_row - div_i_j))
            next_row += 1

        next_row = row_i + 1
        while next_row < n:
            cols.remove((next_row, col_j))
            next_row += 1


if __name__ == '__main__':
    obj = Solution()
    print obj.totalNQueens(4)

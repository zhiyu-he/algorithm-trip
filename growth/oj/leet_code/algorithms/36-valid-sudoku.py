# -*- coding: utf-8 -*-


'''
TIPS: 维护`数字`是否可用, 规则
	a. row, int[9] * 9
	b. col, int[9] * 9
	c. 3x3 sub-box int[3][3] * 9
'''


class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        row, col, sub_box = self._prepare(board)
        return self._check(board, row, col, sub_box, 0)

    def _prepare(self, board):
    	row = []
    	col = []
    	sub_box = []
    	for x in range(9):
    		row.append([-1]*10)
    		col.append([-1]*10)
    	for x in range(3):
    		sub_box.append([])
    		for y in range(3):
    			sub_box[x].append([])
    			sub_box[x][y] = [-1]*10
    			
    	for x in range(9):
    		for y in range(9):
    			if board[x][y] == '.':
    				continue
    			sub_box_x = x / 3
    			sub_box_y = y / 3
    			sub_box[sub_box_x][sub_box_y][int(board[x][y])] = 1
    			row[x][int(board[x][y])] = 1
    			col[y][int(board[x][y])] = 1
    	return row, col, sub_box

    def _check(self, board, row, col, sub_box, pos_row):
    	if pos_row == 9:
    		return True

    	for pos_col in range(9):
    		if board[pos_row][pos_col] is not '.':
    			continue
    		# handle point (pos_row, pos_col)
    		num = 1
    		while num < 10:
    			sub_box_x = pos_row / 3
    			sub_box_y = pos_col / 3
    			if col[pos_col][num] == -1 and row[pos_row][num] == -1 and sub_box[sub_box_x][sub_box_y][num] == -1:
    				col[pos_col][num] = 1
    				row[pos_row][num] = 1
    				sub_box[sub_box_x][sub_box_y][num] = 1
    				f = self._check(board, row, col, sub_box, pos_row+1)
    				if f:
    					return f
    				col[pos_col][num] = -1
    				row[pos_row][num] = -1
    				sub_box[sub_box_x][sub_box_y][num] = -1
    			num += 1
        return False

if __name__ == '__main__':
	obj = Solution()
	print obj.isValidSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]])
	pass
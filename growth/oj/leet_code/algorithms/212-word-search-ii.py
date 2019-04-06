# -*- coding: utf-8 -*-


'''
TIPS:
    1. 当我们提到预处理的时候, 可以对输入进行预处理, 也可以对数据集进行预处理.
        e.g 此题中, 可以对words进行处理. 生产环境中, 如检索, 可以对候选集 和 audience分别进行预处理.
    2. 当我们提到搜索的时候, 考虑搜索的起点是什么, 搜索的终点是什么, 以及起点终点之间的路径是怎么样的, 已经搜索中如何避免重复搜索


TAGS: 预处理(目的减枝), 搜索(DFS)
'''


class TreeNode(object):
    def __init__(self):
        self.child = {}
        self.word = ''

    def is_end(self):
        return '@' in self.child

    def __str__(self):
        return "%s %s" % (self.child, self.word)

class Tire(object):
    def __init__(self):
        self.end_of_word = '@'
        self.root = TreeNode()

    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.child:
                node.child[ch] = TreeNode()
            node = node.child[ch]
        node.child[self.end_of_word] = self.end_of_word
        node.word = word
        return

    def search(self, word):
        start_node = self.root
        for ch in word:
            if ch not in start_node.child:
                return False
            start_node = start_node.child[ch]
        return self.end_of_word in start_node.child




class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        if not board or not board[0]:
            return []
        if not words:
            return []

        tire = Tire()
        for word in words:
            tire.insert(word)
        find_set = set()
        for x in range(len(board)):
            for y in range(len(board[x])):
                if board[x][y] in tire.root.child:
                    self.dfs(board, x, y, tire.root, find_set)
        return list(find_set)

    def dfs(self, board, cur_x, cur_y, cur_node, find_set):
        #print "hand(%d %d) %s cur_node: %s level: %d\n" % (cur_x, cur_y, board[cur_x][cur_y], cur_node, level)
        # handle cur
        ch = board[cur_x][cur_y]
        if ch not in cur_node.child:
            #print "(%d, %d) %s not in cur_node\n" % (cur_x, cur_y, ch)
            return
        if cur_node.child[ch].is_end():
            find_set.add(cur_node.child[ch].word)


        #print "handle(%d %d) %s\n" % (cur_x, cur_y, board[cur_x][cur_y])
        # handle next
        tmp, board[cur_x][cur_y] = board[cur_x][cur_y], '#' # avoid duplicate access
        ds = [(1,0), (-1, 0), (0, 1), (0, -1)]
        for d in ds:
            next_x = cur_x + d[0]
            next_y = cur_y + d[1]
            if next_x < 0 or next_x >= len(board):
                continue
            if next_y < 0 or next_y >= len(board[next_x]):
                continue
            if board[next_x][next_y] == '#':
                continue
            self.dfs(board, next_x, next_y, cur_node.child[tmp], find_set)
        board[cur_x][cur_y] = tmp
        return




if __name__ == '__main__':
    # Testing Tire
    tire = Tire()
    tire.insert("oath")
    tire.insert("pea")
    tire.insert("eat")
    tire.insert("rain")

    print tire.search("oa")
    print tire.search("oath")
    print tire.search("fuck")
    print tire.search("rain")
    board = [
      ['o','a','a','n'],
      ['e','t','a','e'],
      ['i','h','k','r'],
      ['i','f','l','v']
    ]
    words = ["oath","pea","eat","rain"]
    obj = Solution()
    print obj.findWords(board, words)
    board = [["a"]]
    words = ["a"]
    print obj.findWords(board, words)
    board = [["a"],["a"]]
    words = ["aaa"]
    print obj.findWords(board, words)
    pass

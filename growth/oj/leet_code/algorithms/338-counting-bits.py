# -*- coding: utf-8 -*-

class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """

        res = [0, 1, 1]  # [0, 1, 2]
        if num <= 2:
            return res[:num+1]
        last_power_2 = 2
        i = 3
        while i <= num:
            if i != 0 and i & (i - 1) == 0:
                last_power_2 = i
                res.append(1)
            else:
                idx = i % last_power_2
                res.append(res[idx] + res[last_power_2])
            i += 1
        return res
    def normalCountBits(self, num):
        res = [0, 1]
        i = 2
        while i <= num:
            cnt = 0
            handle_i = i
            while handle_i != 0:
                handle_i = handle_i & (handle_i-1)
                cnt += 1
            res.append(cnt)
            i += 1
        return res






if __name__ == '__main__':
    obj = Solution()
    for i in xrange(10):
        print obj.countBits(i)
        print obj.normalCountBits(i)
        print "-----------\n"
    '''
    print obj.countBits(2)
    print obj.countBits(5)
    print obj.countBits(10)
    r1 = obj.countBits(30)
    r2 = obj.normalCountBits(30)
    print r1
    print r2
    '''
    #num = 0
    #for i in obj.countBits(20):
    #    print "num: %d bits: %d\n" % (num, i)
    #    num += 1
    pass

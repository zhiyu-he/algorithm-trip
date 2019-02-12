# -*- coding: utf-8 -*-

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        d = {}
        for ch in s:
            if ch not in d:
                d[ch] = 0
            d[ch] += 1

        for ch in t:
            if ch in d:
                d[ch] -= 1
            else:
                return False
            if d[ch] == 0:
                del d[ch]
        return len(d) == 0


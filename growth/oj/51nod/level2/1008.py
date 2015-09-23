#!/usr/bin/python
#coding=utf-8

import sys

num_arr = sys.stdin.readline().split()

n = long(num_arr[0])
p = long(num_arr[1])

ans = 1L

if n == 1L:
    print n % p
else:

    i = 2L
    while i <= n:
        ans = ans * i % p
        i += 1
    print ans
#!/usr/bin/python
#coding=utf-8


import sys

input = sys.stdin.readline().split()

P = long(input[0])
A = long(input[1])

i = 1L

list = []
while i <= P:
    ans = i % P * i % P
    if ans == A:
        list.append(i)
    i += 1

if 0 == len(list):
    print 'No Solution'
else:
    for num in list:
        print num,
    print

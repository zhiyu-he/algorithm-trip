#!/usr/bin/python
#coding=utf-8

import sys


def print_answer(c5, c2):
    print '5' * c5 + '0' * c2



num = sys.stdin.readline()

arr = sys.stdin.readline().split()

count_5 = 0
count_0 = 0

for i in range(int(num)):
    if int(arr[i]) == 5:
        count_5 += 1
    else:
        count_0 += 1

find_answer = 0

# print "count_5 = %s count_5 * 5 = %s count_5 * 5 mod 9 = %s" % (count_5, count_5 * 5, count_5 * 5 % 9)

while True:
    if count_5 < 9:
        break
    if count_5 * 5 % 9 == 0:
        find_answer = 1
        break;
    count_5 = count_5 - count_5 % 9

if find_answer and count_0 > 0:
    print_answer(count_5, count_0)
elif count_0 == 0:
    print '-1\n'
else:
    print '0\n'


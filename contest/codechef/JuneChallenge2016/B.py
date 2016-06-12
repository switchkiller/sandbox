#!/usr/bin/env python
import sys

#sys.stdin = open('in.txt')

T = input()

for _ in xrange(T):
    if input() % 6:
        sys.stdout.write('Chef\n')
    else:
        sys.stdout.write('Misha\n')

import math
import bisect
from sys import stdin
input = stdin.readline
nxt = lambda : list(map(int, input().split()))

import re

def solve():
    ans = 0
    for text in stdin:
        filtro = re.findall("mul\(\d{1,3}\,\d{1,3}\)", text)
        for mul in filtro:
            x, y = list(map(int, re.findall("\d+", mul)))
            ans += x * y
    print(ans)

def solvee():
    ans = 0
    flag = True
    for text in stdin:
        filtro = re.findall("do\(\)|don\'t\(\)|mul\(\d{1,3}\,\d{1,3}\)", text)
        for expr in filtro:
            if expr == "do()":
                flag = True
                continue
            elif expr == "don\'t()":
                flag = False
                continue
            if flag:
                x, y = list(map(int, re.findall("\d+", expr)))
                ans += x * y
    print(ans)

solvee()

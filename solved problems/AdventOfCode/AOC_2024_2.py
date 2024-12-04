import math
import bisect
from sys import stdin
input = stdin.readline
nxt = lambda : list(map(int, input().split()))

def check(v):
    if len(v) == 1: # just in case
        return 1
    for i in range(1, len(v)):
        if not (1 <= abs(v[i-1] - v[i]) <= 3): # fora do range de diff
            return 0
        if v[0] > v[1] and v[i-1] < v[i]: # deixou de descer
            return 0
        if v[0] < v[1] and v[i-1] > v[i]: # deixou de subir
            return 0
    return 1

def solve():
    ans = 0
    while True:
        v = nxt()
        if v == []:
            break
        ans += check(v)
    print(ans)

def checkk(v):
    if len(v) == 2: # just in case
        return 1
    for i in range(len(v)): # os vetores são pequenos, fiz n^2 msm
        w = []
        for j in range(len(v)): # cria w sem v[i]
            if j != i:
                w.append(v[j])
        if check(w):
            return 1
    return 0

def solvee():
    ans = 0
    while True:
        v = nxt()
        if v == []:
            break
        ans += checkk(v)
    print(ans)

solvee()

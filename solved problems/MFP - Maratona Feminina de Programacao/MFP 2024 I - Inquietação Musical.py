# https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/I
# 
# Implementation, Map.
# 
# Yay, python!
# Fiquei com preguiça de implementar o split() em C++ pra separar cada palavra
# dos versos.
# 
# Faça um map que guarda {palavra, nota}.
# Itere sobre cada verso, sobre cada palavra e use o map para saber a pontuação
# daquele verso, além de ir atualizando o total de pontos.
from sys import stdin
input = stdin.readline
nxt = lambda : list(map(int, input().split()))

N = int(input())
musica = []
for i in range(N):
    verso = input().split()
    musica.append(verso)

M = int(input())
score = {}
for i in range(M):
    [palavra, nota] = input().split()
    score[palavra] = int(nota)

tot = 0    # Total de pontos obtidos na música
best = 0   # Melhor pontuação do verso
ibest = 0  # Índice do verso com a melhor pontuação
for i in range(N):
    pts = 0
    for p in musica[i]:
        if p in score:  # Tem que ver se a palavra 'p' tá no map, senão ERROR
            pts += score[p]
    tot += pts
    if pts >= best:
        best, ibest = pts, i+1  # Mantém o melhor verso

print(tot, ibest)

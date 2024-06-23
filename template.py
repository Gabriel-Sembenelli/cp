import math
import bisect
from sys import stdin
input = stdin.readline
nxt = lambda : list(map(int, input().split()))


for T in range(int(input())):
    x, y, z = nxt()


# UTILITIES ----------------------------------
myset = {1, 2, 3}           # criando set
myset = set([1, 2, 3])      # typecasting lista pra set
myset.add(4)                # insert
setUniao = set1 | set2      # união de sets
setInter = set1 & set2      # interseção de sets

dict = {    "nome":"Gabs",  #
            "altura":1.76,  # criando map com alguns elementos
            "ano":2001      #
}
dict["curso"] = "BCC"       # funciona igual C++
print(dict["abacaba"])      # ERRO, key nao existe e ele nao cria. Testa 'key in dict' antes
dict.pop("nome")            # remove item

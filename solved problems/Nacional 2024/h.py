pot2 = [0]*505
pot2[0] = 1
for i in range(len(pot2)):
    if i == 0:
        continue
    pot2[i] = pot2[i-1] * 2


Mi = input()
Ni = input()
M = [c for c in Mi]
N = [c for c in Ni]

Mast = []
Nast = []

qast = 0
qastM = 0
qastN = 0

Mnum = 0
for i in range(len(M)):
    if M[-(i+1)] == '*':
        continue
    Mnum += int(M[-(i+1)]) * pot2[i]

Nnum = 0
for i in range(len(N)):
    if N[-(i+1)] == '*':
        continue
    Nnum += int(N[-(i+1)]) * pot2[i]



i = 0
for c in M:
    if c == '*':
        Mast.append(i)
        qast += 1
        qastM += 1
    i += 1

i = 0
for c in N:
    if c == '*':
        Nast.append(i)
        qast += 1
        qastN += 1
    i += 1



for mask in range(pot2[qast]):
    newMnum = Mnum
    newNnum = Nnum
    for i in range(qast):
        b = (mask >> i) & 1 # pega o bit
        if i < qastM:
            if b == 1:
                M[Mast[i]] = "1" # to string
                newMnum += pot2[len(M) - Mast[i] - 1]
            else:
                M[Mast[i]] = "0" # to string
        else:
            j = i - qastM
            if b == 1:
                newNnum += pot2[len(N) - Nast[j] - 1]
    #print(M)
    #print(N)
    #print(newMnum)
    #print(newNnum)
    #print()
    if newMnum % newNnum == 0:
        for c in M:
            print(c, end="")
        print()
        break

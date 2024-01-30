/*
https://codeforces.com/contest/1918/problem/C

Bitmasks, Greedy

Note que 
100000...
É maior que 
011111...

Então digamos que a>b. Isso quer dizer que, iterando da esquerda pra direita nos
bits, em algum momento vamos encontrar, digamos, na posição 'm', bits diferentes
entre 'a' e 'b', mais do que isso, encontraremos a[m]==1 e b[m]==0.
Agora, note que não importa oq fizermos nos outros bits dali em diante, 'b'
nunca vai ser maior que 'a', mesmo que todo b[i] à direita de b[m] fosse 1.
Isso ajuda a não nos preocuparmos com o abs() da fórmula.

Uma coisa nesse problema que me ajudou bastante a pensar, foi olhar pra forma
estendida dos números em base 2, tipo:
a[n] * 2^n + ... + a[0] * 2^0

Assim, dá pra pensar no que aquela fórmula faz em cada bit separadamente.
Olhando pro k-ésimo bit:
(a[k] xor x[k]) * 2^k - (b[k] xor x[k]) * 2^k
(a[k] xor x[k] - b[k] xor x[k]) * 2^k

Daqui em diante, ajuda muito lembrar que xor é uma operação bastante usada pra
inverter (toggle) bits, então x[k] tem o "poder" de:
    inverter a[k] e b[k]            (quando x[k] == 1), ou
    manter   a[k] e b[k] como estão (quando x[k] == 0).

Na expressão ali em cima, dá pra ver que se os bits são iguais (a[k] == b[k]),
não muda nada x[k] ser 1 ou 0, a subtração vai dar 0 e consequentemente não
influencia em nada no resultado.
Então podemos pensar só nos bits diferentes.

Se a[k]==1 e b[k]==0, então a expressão contribui positivamente pro resultado,
oq é ruim, pq assumimos que 'a' era maior, então a intenção é aumentar 'b'.
Logo, se fizermos com que x[k]==1, vamos inverter os bits, aí fica a[k]==0 e
b[k]==1, e o resultado da expressão agora é negativo, ou seja, 'b' fica mais
perto de 'a' (a distância entre os dois diminui)

Olhar assim tbm reforça que bits mais à esquerda são mais "importantes", pq a
potência de 2 é cada vez maior, quanto mais à esquerda estamos.

Então vale muito a pena corrigir qualquer bit pra esquerda que tivermos oportunidade.
Daí vem a ideia gulosa de iterar da esquerda pra direita, a partir do m-ésimo bit,
corrigindo oq der, desde que essa correção não faça 'x' ultrapassar o limite 'r'.

Obs.: Inverter o próprio m-ésimo bit não tem propósito, visto que só faremos com
que b>a e aí teremos que resolver o mesmo problema, com possivelmente menos
opções para 'x' que estará mais perto de 'r' por ter x[m]==1.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int a, b, r; cin >> a >> b >> r;
    
    if(a < b) swap(a, b);
    
    int i = 1LL << __lg(a); // Vai no bit ligado mais à esquerda possível
    
    // Acha o bit mais à esquerda que tá diferente entre 'a' e 'b'
    while(i){
        if((a&i) != (b&i)) break; // lição do dia: usem parênteses
        i >>= 1;
    }
    i >>= 1;
    // Nesse ponto, 'i' tá um bit à direita daquele que difere 'a' e 'b'
    // (Pq não faz sentido trocar aquela posição em si, só as próximas)
    
    int x = 0; // O 'x' ótimo será construído a partir das necessidades de trocas.
    while(i){  // Vai andando pra direita até acabar
        if((a&i) and !(b&i) and ((x|i) <= r)) // a[i]=1 e b[i]=0, então x[i] tem que ser 1 pra
            x |= i;                           // inverter isso (desde que 'x' não exceda 'r')
        i >>= 1;
    }
    cout << abs((a^x) - (b^x)) << '\n'; // Nem precisava do 'abs', pelo que foi argumentado.
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
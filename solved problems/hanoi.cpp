#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;

#define endl        "\n"
#define dbg(var)    cout<<#var<<"="<<var<<" "
#define dbgv(var)   cout<<#var<<"=";for(auto e:var)cout<<" "<<e;cout<<endl

const int    INF    = 0x3f3f3f3f;
const ll     LINF   = 0x3f3f3f3f3f3f3f3f;
const int    MOD    = 1e9+7;

/*
Prova - quantidade de movimentos:
    
    Seja 'h(n)' a função que responde quantos movimentos são necessários para
    mover 'n' peças de um pino para o outro, considerando que temos 1 pino auxiliar.
    
    Trivialmente, h(1) = 1, pois basta mover a única peça pra onde desejamos.
    
    h(2) = 2*h(1) + 1, pois precisamos tirar a peça 1 de cima da peça 2, mandando ela
    pro pino auxiliar. Depois, mandamos a peça 2 pro pino de interesse. Finalmente,
    trazemos a peça 1 pro topo da peça 2 de novo.
    
    h(3) = 2*h(2) + 1, pois precisamos tirar as 2 peças de cima da peça 3, mandando
    elas pro pino auxiliar. Isso é o mesmo que resolver h(2) quando o pino de interesse
    é o auxiliar. Depois disso, mandamos a peça 3 pro pino de interesse, depois trazemos
    as 2 peças de volta pro topo da peça 3, ou seja, resolvemos novamente um h(2).
    
    ...
    
    h(n) = 2*h(n-1) + 1, pois resolvemos um h(n-1) pra tirar todas de cima da peça 'n',
    movemos a 'n' pro interesse e resolvemos um h(n-1) pra trazer as peças de volta pro
    topo da peça 'n'.
    
    Vamos abrir a expressão pra h(4):
        h(4)    = 2 * h(3) + 1
                = 2*(2*h(2)+1) + 1
                = 2*2 * h(2) + 2 + 1
                = 2*2*(2*h(1)+1) + 2 + 1
                = 2*2*2 * h(1) + 2*2 + 2 + 1
                = 2*2*2 * 1 + 2*2 + 2 + 1
                = 2^3  + 2^2 + 2^1 + 2^0
    
    Estendendo a ideia pra h(n):
        h(n)    = 2*h(n-1) + 1
                = 2*(2*h(n-2) + 1) + 1
                = 2^2*h(n-2) + 2 + 1
                = 2^3*h(n-3) + 2^2 + 2 + 1
                    ...
                = 2^(n-1)*h(n-(n-1)) + 1 + 2 + ... + 2^(n-2)
                = 2^(n-1)*h(1) + sum(2^i from i=0 to n-2)
                = 2^(n-1)*1 + sum(2^i from i=0 to n-2)
                = sum(2^i from i=0 to n-1)
                = (2^(n-1) * 2 - 2^0)/(2-1)
                = (2^((n-1)+1) - 1)/(1)
                = 2^n - 1
    
    Assim,
    
    h(n) = 2^n - 1


Prova - quais movimentos tomar:
    
    Seja hanoi(n, from, to, aux) uma função que
*/

void hanoi(int n, int from, int to, int aux){
    if(n==1){
        printf("%d %d\n", from, to);
        return;
    }
    hanoi(n-1, from, aux, to);
    printf("%d %d\n", from, to);
    hanoi(n-1, aux, to, from);
}

void solve(int test_case=1){
    ll n; cin>>n;
    ll moves = (1<<n)-1;
    cout << moves << endl;
    hanoi(n, 1, 3, 2);
}


int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}
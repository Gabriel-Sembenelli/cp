#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;

#define endl        "\n"
#define dbgv(var)   cout<<#var<<"=";for(auto e:var)cout<<" "<<e;cout<<endl

/*
Problema geral: Dado um set de moedas, como posso fazer "m" usando o menor número de moedas?

Dado um target "m" e uma lista de números de tamanho "n",
o problema se trata de encontrar uma forma de somar esses números
pra obter "m". Não precisa usar todos e pode repetir os números.

canSum:
    - Devolve se é possível somar os números da lista pra obter "m" (problema de decisão)
    - Complexidade Brute Force:
        Tempo:  O(n^m)
            Pq a altura da árvore é "m" e cada nó chama "n" filhos, que chamam "n" filhos, ...
        Espaço: O(m)
            Pq o máximo da callstack é "m", que corresponde a um dos ramos da árvore
    - Complexidade Memoized:
        Tempo:  O(n*m)
            Pq eu salvo os valores já calculados e corto vários ramos dá árvore, então tenho altura "m" e a cada profundidade só ocorrem "n" iterações
        Espaço: O(m)
            Eu tenho "m" da callstack e "m" do memo, que dá 2m, elimino as ctes.

howSum:
    - Devolve um vetor com uma das possíveis formas de se obter "m" (problema de combinatória)
    - Complexidade Brute Force:
        Tempo:  O(m * n^m)
            Pq eu tenho "n^m" chamadas recursivas e cada uma delas passa um vetor de tamanho no máximo "m"
        Espaço: O(m)
            Novamente callstack
    - Complexidade Memoized:
        Tempo:  O(n * m^2)
            Mesmo que o problema anterior que era O(n*m), mas agora pra cada chamada recursiva eu passo um vetor de tamanho no máx "m"
        Espaço: O(m^2)
            O memo guarda chaves e vetores então, no pior caso, terei "m" chaves que guardam, cada uma, um vetor de tamanho "m"

bestSum:
    - Devolve um vetor com a melhor forma de se obter "m", i.e., aquela que usa a menor qtd de números (problema de otimização)
    - Complexidade Brute Force:
        Tempo:  O(m * n^m)
            Mesma coisa que o problema anterior
        Espaço: O(m^2)
            Precisei criar um vetor auxiliar na recursão, então posso ter uma stack de "m", cada uma com um vetor auxiliar de "m"
    - Complexidade Memoized:
        Tempo:  O(n * m^2)
            Mesmo que o memoize anterior
        Espaço: O(m^2)
            Mesmo que o memoize anterior
*/


map<ll, bool> memo1;
bool canSum(ll target, vector<ll> numbers){
    if(memo1.count(target)) return memo1[target];
    if(target == 0) return memo1[target] = true;
    if(target < 0) return memo1[target] = false;
    bool ret = false;
    for(auto e:numbers){
        if(canSum(target - e, numbers)) return memo1[target] = true;
    }
    return memo1[target] = false;
}


map<ll, vector<ll>> memo;
vector<ll> howSum(ll target, vector<ll> numbers){
    if(memo.count(target)) return memo[target];
    vector<ll> ret;
    if(target == 0){
        ret.push_back(0);
        return memo[target] = ret;
    }
    if(target < 0){
        return memo[target] = ret;
    }
    
    for(auto e:numbers){
        ret = howSum(target-e, numbers);
        if(ret.size()){
            ret.push_back(e);
            return memo[target] = ret;
        }
    }
    return memo[target] = ret;
}


//map<ll, vector<ll>> memo;
vector<ll> bestSum(ll target, vector<ll> numbers){
    if(memo.count(target)) return memo[target];
    vector<ll> ret;
    if(target == 0){
        ret.push_back(0);
        return memo[target] = ret;
    }
    if(target < 0){
        return memo[target] = ret;
    }
    vector<ll> aux;
    for(auto e:numbers){
        aux = bestSum(target-e, numbers);
        if(aux.size()){
            aux.push_back(e);
            memo[target] = aux;
            if(ret.size()==0 || aux.size()<ret.size()) ret = aux;
        }
    }
    return memo[target] = ret;
}


void solve(int test_case=1){
    memo.clear();
    dbgv(bestSum(7, {2, 3}));
    memo.clear();
    dbgv(bestSum(7, {3, 4, 5, 7}));
    memo.clear();
    dbgv(bestSum(7, {2, 4}));
    memo.clear();
    dbgv(bestSum(8, {2, 3, 5}));
    memo.clear();
    dbgv(bestSum(100, {1, 2, 5, 25}));
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
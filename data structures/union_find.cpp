#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+1;
vector<int> p(MAX);  // pais
vector<int> w(MAX);  // weights

int find(int x){                //  Função para achar o patriarca de 'x'
    if(p[x] == x) return x;     //      Se o pai de 'x' é ele mesmo, então 'x' é o patriarca
    return p[x] = find(p[x]);   //      Senão, acha o patriarca do pai de 'x' e transforma no pai de 'x' (otimização)
}

void join(int x, int y){        //  Função para unir famílias de 'x' e 'y'
    x = find(x);                //      Basta unir os patriarcas
    y = find(y);                //      de 'x' e 'y'

    if(x == y) return;          //      Se o patriarca é o mesmo, então já estão unidos

    if(w[x] > w[y]){            //      Família de 'x' é maior:
        p[y] = x;               //          Então pai de 'y' se torna 'x'
    }else if(w[x] < w[y]){      //      Família de 'y' é maior:
        p[x] = y;               //          Então pai de 'x' se torna 'y'
    }else if(w[x] == w[y]){     //      Famílias com mesmo peso:
        p[y] = x;               //          Escolhe pai arbitrariamente
        w[x]++;                 //          Aumenta o peso dele
    }
}

void init(int n){               //  Função para inicializar vetores 'p' e 'w'
    for(int i=1; i<=n; i++){
        p[i] = i;               //      p[1]=1, p[2]=2, ...
        w[i] = 0;               //      w = {0, 0, 0, ...}
    }
}
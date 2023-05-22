#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;


#define MAX 100001
vector<ll> primes;

void crivo(){
    ll n=MAX;
    int cr[n]; for(int i=0; i<n; i++) cr[i]=0;
    for(ll i=2; i*i<n; i++){
        if(cr[i]==0){
            for(ll j=i*i; j<n; j+=i){
                cr[j]=1;
            }
        }
    }
    for(ll i=2; i<n; i++){
        if(cr[i]==0){
            primes.push_back(i);
        }
    }
}

vector<ll> factors(ll n){
    vector<ll> re;
    for(auto p:primes){
        if(p*p > n){                // Nesse ponto, já fatorei 'n' em todos os
            if(n>1){                // primos antes de 'p', então se p*p>n,
                re.push_back(n);    // não tem mais o que fazer, ou seja, 'n'
                n=1;                // não pode mais ser fatorado, e o valor
                break;              // que sobrou é primo
            }
        }else{
            while(n % p == 0){
                re.push_back(p);
                n /= p;
            }
        }
    }
    return re;
}

void solve(int test_case=1){
    int a = 360;
    vector<ll> f;
    f = factors(a);
    for(auto e:f) cout << e << ' '; cout << endl;
}


int main(){
    crivo();
    int t=1;
    //cin>>t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    
    return 0;
}
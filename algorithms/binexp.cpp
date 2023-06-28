#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9+7;

long long binexpMOD(long long a, long long n){
    if(n==0) return 1;
    long long ret = binexp(a, n/2);
    if(n%2) return ((ret%MOD)*(ret%MOD)*(a%MOD))%MOD;
    return ((ret%MOD)*(ret%MOD))%MOD;
}

long long binexp(long long a, long long n){
    if(n==0) return 1;
    long long ret = binexp(a, n/2);
    if(n%2) return ret*ret*a;
    return ret*ret;
}

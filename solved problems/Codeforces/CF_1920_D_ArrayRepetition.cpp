/*
https://codeforces.com/contest/1920/problem/D
Solved in cpp & py
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int nxt(){ int x; cin >> x; return x; }

vector<pair<int,int>> op;
vector<int> tam;

int search(int k){
    while(true){
        int i = lower_bound(begin(tam), end(tam), k) - begin(tam);
        if(op[i].first == 1)
            return op[i].second;
        k = ((k-1) % tam[i-1]) + 1; // Find equivalent index at previous array
    }
}

void solve(){
    int n(nxt()), q(nxt());
    op.resize(n);   // Save query type and value
    tam.resize(n);  // Resulting size for each query
    int lim = 1e18;
    for(int i=0; i<n; i++){
        int b(nxt()), x(nxt());
        op[i] = {b, x};
        if(i == 0){ tam[0] = 1; continue; }
        if(tam[i-1] >= lim){ tam[i] = INF; continue; }
        
        if(b == 1){
            if(tam[i-1] + 1 > lim)
                tam[i] = INF;
            else
                tam[i] = tam[i-1] + 1;
        }else{
            if(tam[i-1] > lim / (x + 1)) // Check with division to avoid OF
                tam[i] = INF;
            else
                tam[i] = tam[i-1] * (x + 1);
        }
    }
    while(q--)
        cout << search(nxt()) << ' ';
    cout << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

// -----------------------------------------------------------------------------

/*
from bisect import bisect_left
from sys import stdin
input = stdin.readline
nxt = lambda : list(map(int, input().split()))


def search(k):
    while True:
        i = bisect_left(tam, k)
        if(op[i][0] == 1):
            return op[i][1]
        k = ((k-1) % tam[i-1]) + 1


lim = int(1e18)
INF = int(2e18)


for T in range(int(input())):
    n, q = nxt()
    op = [0]*n
    tam = [0]*n
    for i in range(n):
        b, x = nxt()
        op[i] = [b, x]
        if i == 0:
            tam[0] = 1
            continue
        
        if b == 1:
            tam[i] = tam[i-1] + 1
        else:
            tam[i] = tam[i-1] * (x + 1)
        
        if tam[i] > lim:
            tam[i] = INF
    for k in nxt():
        print(search(k), end=" ")
    print()
*/
/*
https://codeforces.com/contest/1920/problem/C
Number Theory

Recall that:
a = b (mod m)   <->   m | (a-b)
Also:
m1 | X  and  m2 | m1  ->  m2 | X

So makes sense to pick the greatest m that divides (a-b), which is |a-b| itself

So, a pair (a[i], a[i+k]) will give m1
and a pair (a[j], a[j+k]) will give m2

To choose an m that satisfies m1 and m2, makes sense to pick m = gcd(m1, m2)
Do this iteratively for every pair. If m = 1 at the end, Allen gains no points.
*/
#include <bits/stdc++.h>
using namespace std;

int nxt(){ int x; cin >> x; return x; }

int n;
vector<int> a;

bool ok(int d){
    if(d == n) return true;
    int G = abs(a[0] - a[d]);
    for(int i=0; i<n-d; i++) G = gcd(G, abs(a[i] - a[i+d]));
//  for(int i=d; i<n; i++)   G = gcd(G, abs(a[i%d] - a[i])); same, but % costy
    return G != 1;
}

void solve(){
    n = nxt();
    a.resize(n); for(auto &e:a) e = nxt();
    int ans = 0;
    for(int i=1; i*i<=n; i++){
        if(n % i) continue;
        ans += ok(i);
        if((n/i) != i) ans += ok(n/i);
    }
    cout << ans << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
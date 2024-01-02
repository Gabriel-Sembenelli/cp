#include <bits/stdc++.h>
using namespace std;

// n := max range

// Naive
// O(n)
void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int fence[101]{};
    for(int i=a; i<b; i++) fence[i] = 1;
    for(int i=c; i<d; i++) fence[i] = 1;
    int ans = 0;
    for(int i=0; i<101; i++) ans += fence[i];
    cout << ans << '\n';
}

// Geometric
// O(1)
void solve2(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int Union = (b - a) + (d - c);
    int Inter = max(0, min(b,d) - max(a,c));
    cout << Union - Inter << '\n';
}

signed main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve2();
    
    return 0;
} 
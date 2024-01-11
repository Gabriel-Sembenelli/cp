/*
https://codeforces.com/contest/17/problem/B

Directed MST
*/
#include <bits/stdc++.h>
using namespace std;

// My Solution -----------------------------------------------------------------
typedef pair<int, pair<int,int>> Edge;
#define C first
#define A second.first
#define B second.second

vector<int> p, w, pred;

int find(int x){ return p[x] == x ? x : p[x]=find(p[x]); }

void join(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    
    if(w[x] < w[y])
        p[x] = y;
    else if(w[y] < w[x])
        p[y] = x;
    else{
        p[y] = x;
        w[x]++;
    }
}

void solve(){
    int n; cin >> n;
    p.resize(n+1), w.resize(n+1), pred.resize(n+1);
    int q[n+1]; // This vector is useless
    for(int i=1; i<=n; i++){
        cin >> q[i];
        p[i] = i;
    }
    // Cheap edge, more priority
    int m; cin >> m;
    priority_queue<Edge> pq;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        pq.push({-c,{a,b}});
    }
    // Kruskal
    int ans = 0;
    while(!pq.empty()){
        Edge T = pq.top(); pq.pop();
        if(pred[T.B]) continue; // T.B already have a supervisor
        join(T.A, T.B);
        pred[T.B] = T.A;
        ans += (-T.C);
    }
    // Checking if the result is a single tree
    int paizao = find(1);
    for(int i=2; i<=n; i++)
        if(find(i) != paizao)
            ans = -1;
    
    cout << ans << '\n';
}
// -----------------------------------------------------------------------------

// Editorial's idea ------------------------------------------------------------
void solve2(){
    const int INF = 0x3f3f3f3f;
    int n; cin >> n;
    int q[n+1]; // This vector is useless
    int cost[n+1];
    for(int i=1; i<=n; i++){
        cin >> q[i];
        cost[i] = INF;
    }
    int m; cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        cost[b] = min(cost[b], c);
    }
    int ans = 0, noSup = 0;
    for(int i=1; i<=n; i++){
        if(cost[i] == INF) noSup++;
        else ans += cost[i];
    }
    cout << (noSup > 1 ? -1 : ans) << '\n';
}
// -----------------------------------------------------------------------------

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
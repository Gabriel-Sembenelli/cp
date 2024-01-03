//https://codeforces.com/problemset/problem/1555/B
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

// my solution
void solve(){
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    
    int wSpace = max(x1, W - x2);
    int hSpace = max(y1, H - y2);
    
    if(wSpace >= w or hSpace >= h){
        cout << 0 << '\n';
        return;
    }
    
    int ans = INF;
    if(w + (x2 - x1) <= W) ans = min(ans, w - wSpace);
    if(h + (y2 - y1) <= H) ans = min(ans, h - hSpace);
    
    cout << (ans == INF ? -1 : ans) << '\n';
}

// solution after reading editorial
void solve2(){
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    
    int ans = INF;
    if(w + (x2 - x1) <= W){
        ans = min(ans, max(0, w - x1));
        ans = min(ans, max(0, x2 - (W - w)));
    }
    if(h + (y2 - y1) <= H){
        ans = min(ans, max(0, h - y1));
        ans = min(ans, max(0, y2 - (H - h)));
    }
    
    cout << (ans == INF ? -1 : ans) << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
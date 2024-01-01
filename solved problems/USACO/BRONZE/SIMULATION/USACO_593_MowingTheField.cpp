// simple solution without using advanced data structures
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve(){
    //int farm[2020][2020]{}; // segfault
    vector<vector<int>> farm(2020, vector<int>(2020)); // no segfault
    int x = 1010, y = 1010;
    int t = 1;
    farm[x][y] = t;
    int n; cin >> n;
    int ans = INF;
    while(n--){
        char D; int s;
        cin >> D >> s;
        int dx, dy;
        if(D == 'N') dx = 0, dy = 1;
        if(D == 'S') dx = 0, dy =-1;
        if(D == 'E') dx = 1, dy = 0;
        if(D == 'W') dx =-1, dy = 0;
        while(s--){
            t++, x += dx, y += dy;
            if(farm[x][y]) ans = min(ans, t-farm[x][y]);
            farm[x][y] = t;
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << '\n';
}

signed main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 
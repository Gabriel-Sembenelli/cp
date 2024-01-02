#include <bits/stdc++.h>
using namespace std;

// "All x-coordinates are distinct from each-other,
// and similarly for the y-coordinates"
// Therefore, there are no collinear cows, which means that a cow can
// only be stuck in a rut of another cow going in a different direction.

const int INF = INT_MAX;

struct Cow {
    int x, y, diag, xMax, yMax, grass, id;
    char dir;
};

bool cmp(Cow a, Cow b){ return a.diag < b.diag; }

void solve(){
    int n; cin >> n;
    Cow cow[n];
    for(int i=0; i<n; i++){
        cow[i].id = i;
        cin >> cow[i].dir >> cow[i].x >> cow[i].y;
        cow[i].diag = cow[i].x + cow[i].y;
        cow[i].grass = INF;
        cow[i].xMax = INF;
        cow[i].yMax = INF;
    }
    sort(cow, cow + n, cmp); // don't know if it's possible to do this problem without sorting
    
    // iterate cows from highest to lowest diagonal
    // for each cow, check how much the others block it's rut path
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(cow[i].dir == cow[j].dir) continue; // guaranteed no rut collision
            if(cow[i].diag == cow[j].diag) continue; // same diagonal doesn't collide
            
            if(cow[i].dir == 'E'){
                if(cow[i].y < cow[j].y) continue;
                if(cow[j].yMax < cow[i].y) continue;
                cow[i].grass = min(cow[i].grass, cow[j].x - cow[i].x); // collisions minimize grass eaten
                cow[i].xMax = min(cow[i].xMax, cow[j].x);              // and final coordinates
            }
            if(cow[i].dir == 'N'){
                if(cow[i].x < cow[j].x) continue;
                if(cow[j].xMax < cow[i].x) continue;
                cow[i].grass = min(cow[i].grass, cow[j].y - cow[i].y);
                cow[i].yMax = min(cow[i].yMax, cow[j].y);
            }
        }
    }
    int i = 0;
    int ans[n];
    for(auto c:cow) // using id to "unsort" the cows
        ans[c.id] = c.grass;
    for(auto g:ans){
        if(g == INF) cout << "Infinity\n";
        else cout << g << '\n';
    }
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 
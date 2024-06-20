/*
https://csacademy.com/lesson/breadth_first_search

BFS MultiSource

Each special cell is a source.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

const int MAXN = 1123;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

using Point = pair<int,int>;
#define I first
#define J second

void solve(){
    int N, M, K; cin >> N >> M >> K;

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            cin >> grid[i][j];
    
    queue<Point> q;
    for(int k=0; k<K; ++k){
        int i, j; cin >> i >> j;
        q.push({--i, --j});
        dist[i][j] = 1;
    }

    while(!q.empty()){
        Point t = q.front(); q.pop();
        vector<int> di = {0, -1, 0, 1};
        vector<int> dj = {1, 0, -1, 0};
        for(int k=0; k<4; ++k){
            int newI = t.I + di[k], newJ = t.J + dj[k];
            if(min(newI, newJ) < 0 or newI >= N or newJ >= M) continue;
            if(grid[newI][newJ] == '#' or dist[newI][newJ]) continue;
            dist[newI][newJ] = dist[t.I][t.J] + 1;
            q.push({newI, newJ});
        }
    }

    int ans = 0;
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            if(grid[i][j] == '.')
                ans += dist[i][j] - 1;
    
    cout << ans << '\n';
}

signed main(){
    setIO();
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}

void setIO(string file){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(!file.empty()){
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

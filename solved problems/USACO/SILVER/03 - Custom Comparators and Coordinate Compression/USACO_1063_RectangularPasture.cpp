/*
Coordinate Compression, 2D Prefix Sum

Had to look up the solution. Couldn't figure it all by myself.
https://usaco.guide/problems/usaco-1063-rectangular-pasture/solution

The main missing point was that all this O(N^2) approach is possible because:
(*) All x coordinates are distinct from each other, as well as y coordinates.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2510;
int psum[MAXN][MAXN];

using Point = pair<int,int>;
#define X first
#define Y second

void solve(){
    int N; cin >> N;
    vector<Point> pts(N);
    for(auto &[x,y]:pts) cin >> x >> y;
    
    // Coordinate Compression (can be done like this because (*))
    sort(begin(pts), end(pts), [](const Point &a, const Point &b){ return a.Y < b.Y; });
    for(int i=0; i<N; i++) pts[i].Y = i+1; // 1-indexing
    sort(begin(pts), end(pts));
    for(int i=0; i<N; i++) pts[i].X = i+1;
    
    // Making 2D Prefix Sum
    for(auto [x,y]:pts)
        psum[x][y]++;
    for(int x=1; x<MAXN; x++)
        for(int y=1; y<MAXN; y++)
            psum[x][y] += psum[x-1][y] + psum[x][y-1] - psum[x-1][y-1];
    
    int ans = N + 1; // Account each cow alone and 0 cows possibilites
    // Account pairs and cows above/below each pair (only works because (*), i.e., double-counting will not occur)
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            int loY = min(pts[i].Y, pts[j].Y);
            int hiY = max(pts[i].Y, pts[j].Y);
            int loX = pts[i].X;
            int hiX = pts[j].X;
            
            int ptsBelow = psum[hiX][loY] - psum[loX-1][loY];
            int ptsAbove = psum[hiX][N] - psum[hiX][hiY-1]
                            - psum[loX-1][N] + psum[loX-1][hiY-1];
            
            ans += ptsBelow * ptsAbove;
        }
    }
    
    cout << ans << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
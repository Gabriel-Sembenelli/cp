/*
https://atcoder.jp/contests/agc015/tasks/agc015_c

2D Prefix Sum, Implicit Graphs

I had to look up AtCoder's Editorial to note the implicit forest and its
properties.

The conditions explained in the problem statement define the grid as an implicit
forest graph. To cut out a region from it does not change this property.
So, to determine the number of connected components in a forest, it is just the
number of vertices - the number of edges.
Use 2D prefix sums to get the number of vertices/edges of a submatrix.
I had to separate the prefix sum for edges into up-edges and left-edges, due to
implementation purposes.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

const int MAXN = 2123;
int grid[MAXN][MAXN];
int prefV[MAXN][MAXN];      // 2D prefix sum for vertices
int prefEup[MAXN][MAXN];    // 2D prefix sum for up edges
int prefEle[MAXN][MAXN];    // 2D prefix sum for left edges

void solve(){
    int N, M, Q; cin >> N >> M >> Q;
    for(int i=1; i<=N; ++i){
        string line; cin >> line;
        for(int j=1; j<=M; ++j){
            grid[i][j] = (line[j-1] == '1');
            prefV[i][j] = prefV[i-1][j] + prefV[i][j-1] - prefV[i-1][j-1];
            prefEup[i][j] = prefEup[i-1][j] + prefEup[i][j-1] - prefEup[i-1][j-1];
            prefEle[i][j] = prefEle[i-1][j] + prefEle[i][j-1] - prefEle[i-1][j-1];
            if(grid[i][j]){
                ++prefV[i][j];
                prefEup[i][j] += grid[i-1][j];
                prefEle[i][j] += grid[i][j-1];
            }
        }
    }
    
    while(Q--){
        int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
        int V = prefV[i2][j2] - prefV[i1-1][j2] - prefV[i2][j1-1] + prefV[i1-1][j1-1];
        int E = prefEup[i2][j2] - prefEup[i1][j2] - prefEup[i2][j1-1] + prefEup[i1][j1-1]
              + prefEle[i2][j2] - prefEle[i1-1][j2] - prefEle[i2][j1] + prefEle[i1-1][j1];
        cout << V - E << '\n';
    }
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
        (void)!freopen((file + ".in").c_str(), "r", stdin);
        (void)!freopen((file + ".out").c_str(), "w", stdout);
    }
}

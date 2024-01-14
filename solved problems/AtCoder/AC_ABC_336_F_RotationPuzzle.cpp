/*
https://atcoder.jp/contests/abc336/tasks/abc336_f

Techniques:
    Recursive Complete Search
    Meet in the middle

Idea reference: (didn't solve it all by myself)
https://youtu.be/g2-e1ntHOq4?si=BCdumbOa2niFcraq&t=210
*/
#include <bits/stdc++.h>
using namespace std;

int nxt(){ int x; cin >> x; return x; }


typedef vector<vector<int>> Matrix;
int H, W;
Matrix mat;
vector<map<Matrix, int>> memo(2); // memo[0] = ida, memo[1] = volta

void search(int x, int y, int ida, int moves, int cnt, Matrix aux){
    map<Matrix, int> &MM = memo[ida];
    
    // Save the minimum amount of moves to reach this state
    if(MM.count(aux))
        MM[aux] = min(MM[aux], moves);
    else
        MM[aux] = moves;
    
    // Don't do more than 10 moves
    if(cnt == 10) return;
    
    moves = MM[aux];
    
    // Rotate
    Matrix tmp = aux;
    for(int i=0; i<H-1; i++)
        for(int j=0; j<W-1; j++)
            aux[i+x][j+y] = tmp[H-2-i+x][W-2-j+y];
    
    // Search the next moves
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            if(i==x and j==y) continue; // Don't do the same move again
            search(i, j, ida, moves+1, cnt+1, aux);
        }
    }
}

void solve(){
    H = nxt(), W = nxt();
    mat.resize(H, vector<int>(W));
    // Reading input
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            mat[i][j] = nxt();
    
    // Searching from start
    for(int i=0; i<=1; i++)
        for(int j=0; j<=1; j++)
            search(i, j, 0, 0, 0, mat);
    
    // Making mat = {1,2,3,...}
    for(int i=0, c=1; i<H; i++)
        for(int j=0; j<W; j++)
            mat[i][j] = c++;
    
    // Searching from end
    for(int i=0; i<=1; i++)
        for(int j=0; j<=1; j++)
            search(i, j, 1, 0, 0, mat);
    
    // Meet in the middle (if some state from start match with some from end)
    int ans = 25;
    for(auto [M,x]:memo[0])
        if(memo[1].count(M))
            ans = min(ans, memo[0][M] + memo[1][M]);
    
    cout << (ans <= 20 ? ans : -1) << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

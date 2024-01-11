/*
Almost the same solution as the one presented in CPH
Only added the condition of '*' cells
*/
#include <bits/stdc++.h>
using namespace std;
 
const int N = 8;
char board[N][N];
int col[N]{}, diag1[N*2-1]{}, diag2[N*2-1]{};
int ans = 0;
 
void search(int y){
    if(y == N){ans++; return;}
    for(int x=0; x<N; x++){
        if(col[x] or diag1[x+y] or diag2[x-y+N-1] or board[y][x]=='*') continue;
        col[x] = diag1[x+y] = diag2[x-y+N-1] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+N-1] = 0;
    }
}
 
signed main(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];
    search(0);
    cout << ans << '\n';
    
    return 0;
}
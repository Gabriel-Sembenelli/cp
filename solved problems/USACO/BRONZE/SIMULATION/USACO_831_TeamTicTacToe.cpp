// simple solution without using advanced data structures
#include <bits/stdc++.h>
using namespace std;

// win[i][j] == 1  iff  team (i,j) won at any place
int win[26][26]{};

void check(char c1, char c2, char c3){
    // 0-indexing characters
    c1 -= 'A'; c2 -= 'A'; c3 -= 'A';
    
    // all different
    if(c1 != c2 and c2 != c3 and c3 != c1)
        return;
    
    // all equal
    if(c1 == c2 and c2 == c3){
        win[c1][c1] = 1;
        return;
    }
    
    // only 2 equal
    if(c1 == c2) swap(c2, c3); // just to guarantee c1 != c2
    win[c1][c2] = 1;
    win[c2][c1] = 1;
}

void solve(){
    char board[3][3];
    for(auto &c:board) cin >> c;
    
    // note that this will triple check each diagonal but there's no problem
    for(int i=0; i<3; i++){
        check(board[i][0], board[i][1], board[i][2]); // lines
        check(board[0][i], board[1][i], board[2][i]); // columns
        check(board[0][0], board[1][1], board[2][2]); // diag1
        check(board[0][2], board[1][1], board[2][0]); // diag2
    }
    
    int solo=0, duo=0;
    for(int i=0; i<26; i++){ // solo wins at the main diagonal
        solo += win[i][i]; 
        for(int j=i+1; j<26; j++) // duo wins above the main diagonal
            duo += win[i][j];
    }
    
    cout << solo << '\n' << duo << '\n';
}

signed main(){
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 
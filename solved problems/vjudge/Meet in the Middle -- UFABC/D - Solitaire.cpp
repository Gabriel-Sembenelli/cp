// C++14
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x),end(x)
#define X first
#define Y second

using Map = unordered_map<string, int>;
using VP = vector<pair<int,int>>;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

bool canMove(VP &piece, int p, int j, int mul){
    pair<int,int> newPos = {piece[p].X + mul * dx[j],
                            piece[p].Y + mul * dy[j]};
    
    if( newPos.X < 1 or newPos.X > 8 or
        newPos.Y < 1 or newPos.Y > 8)
        return false;
    
    for(int p2=0; p2<4; p2++){
        if(p == p2) continue;
        if(piece[p2] == newPos) return false;
    }
    
    piece[p] = newPos;
    return true;
}

void search(Map &poss, VP piece, int move){
    vector<string> board(9, string(9,'.'));
    for(auto pc:piece) board[pc.X][pc.Y] = '*';
    
    string hash;
    for(auto s:board) hash += s;
    
    if(poss.count(hash) and poss[hash] <= move) return;
    
    poss[hash] = move;
    
    if(move == 4) return;
    
    for(int p=0; p<4; p++){
        for(int j=0; j<4; j++){
            VP tmp = piece;
            if      (canMove(tmp, p, j, 1)) search(poss, tmp, move+1);
            else if (canMove(tmp, p, j, 2)) search(poss, tmp, move+1);
        }
    }
}

void solve(){
    Map poss0, poss1;
    VP piece(4);
    
    for(auto &p:piece) cin >> p.X >> p.Y;
    search(poss0, piece, 0);
    
    for(auto &p:piece) cin >> p.X >> p.Y;
    search(poss1, piece, 0);
    
    for(auto FS:poss0){
        string hash = FS.first;
        if(poss1.count(hash)){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

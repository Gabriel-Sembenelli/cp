#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

vector<vector<int>> mat, aux;
int n;

bool ok(){
    for(int i=1; i<n; ++i){
        for(int j=1; j<n; ++j){
            if(!(mat[i-1][j] <= mat[i][j])) return false;
            if(!(mat[i][j-1] <= mat[i][j])) return false;
        }
    }
    return true;
}

void gira(){
    for(int i=0, j2=0; i<n; ++i, ++j2){
        for(int j=0, i2=n-1; j<n; ++j, --i2){
            mat[i2][j2] = aux[i][j];
        }
    }
    aux = mat;
}


void solve(){
    cin >> n;
    mat.resize(n, vector<int>(n));
    aux.resize(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> mat[i][j];
            aux[i][j] = mat[i][j];
        }
    }
    for(int c = 0; c < 4; c++){ // pun intended
        if(ok()){
            cout << c << '\n';
            return;
        }
        gira();
    }
}

signed main(){
	//int t; cin >> t; while(t--);
	solve();
}
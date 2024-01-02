#include <bits/stdc++.h>
using namespace std;

void solve(){
    int M, N, K; cin >> M >> N >> K;
    char signal[M][N];
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            cin >> signal[i][j];
    for(int i=0; i<M; i++){
        for(int x=0; x<K; x++){  // output each line K times
            for(int j=0; j<N; j++){
                for(int y=0; y<K; y++){  // output each character K times
                    cout << signal[i][j];
                }
            }
            cout << '\n';
        }
    }
}

signed main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 
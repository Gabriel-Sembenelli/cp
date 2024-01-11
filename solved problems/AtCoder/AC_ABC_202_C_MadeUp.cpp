#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int N; cin >> N;
    map<int, int> A; // {element, Qoccur}
    for(int i=0; i<N; i++){
        int a; cin >> a;
        A[a]++;
    }
    vector<int> B(N+1); // 1 indexed
    for(int i=1; i<=N; i++) cin >> B[i];
    
    int ans = 0;
    for(int i=0; i<N; i++){
        int c; cin >> c;    // B[c] can form a pair with all
        ans += A[B[c]];     // elements in A with the same value
    }
    
    cout << ans << '\n';
}

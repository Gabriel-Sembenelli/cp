/*
Approach: Position all cows optimally respecting constraints
and then find the first free space to put cow 1
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N, M, K; cin >> N >> M >> K;
    int order[M]; for(auto &e:order) cin >> e;
    int used[N+1]{}, cowPos[N+1]{};
    while(K--){
        int c, p; cin >> c >> p;
        if(c == 1){ cout << p << '\n'; return; } // 1 is fixed
        cowPos[c] = p; // Fix c-th cow position
        used[p] = c;   // Mark this position as used
    }
    // Everyone that comes after 1 in the hierarchy go as late as possible
    for(int c=M-1, p=N; c>=0; c--){
        int cow = order[c];
        if(cow == 1) break; // Don't put 1 late
        if(!cowPos[cow]){ // Current cow isn't positioned
            while(used[p]) p--; // Find latest free space
            used[p] = cow;      // to put current cow
            cowPos[cow] = p;    //
            p--;                //
        }else{
            p = cowPos[cow] - 1; // Current cow was already fixed
        }
    }
    // Everyone that comes before 1 in the hierarchy go as early as possible
    for(int c=0, p=1; c<M; c++){
        int cow = order[c];
        if(!cowPos[cow]){
            while(used[p]) p++; // Find earliest free space
            if(cow == 1){ cout << p << '\n'; return; } // Current cow is 1
            used[p] = cow;
            cowPos[cow] = p;
            p++;
        }else{
            p = cowPos[cow] + 1;
        }
    }
    // If 1 still not positioned, it means that 1 wasn't in the hierarchy,
    // so just find the first free space to put it
    for(int p=1; p<=N; p++){
        if(!used[p]){ cout << p << '\n'; return; }
    }
}

signed main(){
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

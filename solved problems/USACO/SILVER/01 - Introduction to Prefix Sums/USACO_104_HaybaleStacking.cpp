/*
Submited through SPOJ:
https://www.spoj.com/problems/HAYBALE/

Offline Prefix Sum (Técnica da Ondinha)

Just save the intervals to do the accumulation later.
When a query tells to increase an interval [A,B] by 'x', you can save this
operation for later just doing:
    prefix[A] += x;
    prefix[B+1] -= x;
After you save all queries, do only one accumulation from 1 to N.
This is called an "offline" approach.
*/
#include <bits/stdc++.h>
using namespace std;

int height[1000001];

void solve(){
    int N, K; cin >> N >> K;
    while(K--){
        int A, B; cin >> A >> B;
        height[A]++;
        height[B+1]--;
    }
    for(int i=1; i<=N; i++)
        height[i] += height[i-1];
    
    sort(height+1, height+1+N);
    
    cout << height[(N+1)/2] << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

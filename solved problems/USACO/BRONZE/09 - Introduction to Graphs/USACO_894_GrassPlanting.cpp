/*
Note that the answer is directly related to the degree of the nodes.
More specifically, we find the node 'v' that has the greatest degree, and the
answer will be deg[v]+1, because we need unique types of grass for 'v' and all
of its neighbors.
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N; cin >> N;
    vector<int> deg(N+1);
    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    cout << 1 + *max_element(begin(deg), end(deg)) << '\n';
}

signed main(){
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

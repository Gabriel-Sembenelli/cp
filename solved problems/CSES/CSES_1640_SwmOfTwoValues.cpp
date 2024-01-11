/*
This solution sorts the string and uses Two Pointers to search answer
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define dbg(V) cerr<<#V<<"= "<<V<<" "
#define dbgv(V) cerr<<#V<<"=";for(auto e:V)cerr<<" "<<e;cerr<<endl
#define dbgm(V) cerr<<#V<<"=";for(auto [f,s]:V)cerr<<" {"<<f<<","<<s<<"},";cerr<<endl
#define int long long
#define sz(x) (int)x.size()
 
const int INF = 0x3f3f3f3f3f3f3f3fLL;
 
void solve(){
    int n, x; cin>>n>>x;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        int e; cin>>e;
        a[i] = {e, i+1};
    }
    sort(a.begin(), a.end());
    int l=0, r=n-1;
    while(l<r){
        int sum = a[l].first + a[r].first;
        if(sum < x) l++;
        else if(sum > x) r--;
        else{cout << a[l].second << " " << a[r].second << endl; return;}
    }
    cout << "IMPOSSIBLE" << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
}
